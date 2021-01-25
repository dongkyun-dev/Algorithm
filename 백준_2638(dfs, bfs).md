[백준_2638(dfs, bfs)](https://www.acmicpc.net/problem/2638)

---

```c++
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int MAX = 100;

typedef struct
{
    int x, y;
} Dir;

typedef struct
{
    int x, y;
} Air;

queue<Air> q;
Dir dirMove[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool visited[MAX][MAX];
int graph[MAX][MAX];
int chkSurface[MAX][MAX];
int N, M;
int cnt;
int cheeseNum;

// bool chk()
// {
//     for (int i = 1; i < N - 1; i++)
//     {
//         for (int j = 1; j < M - 1; j++)
//         {
//             if (graph[i][j])
//                 return false;
//         }
//     }
//     return true;
// }

void dfs(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dirMove[i].x;
        int nextY = y + dirMove[i].y;
        if (graph[nextX][nextY] && 0 <= nextX && nextX < N && 0 <= nextY && nextY < M)
        {
            chkSurface[nextX][nextY] += 1;
        }
        if (!visited[nextX][nextY])
        {
            if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M && !graph[nextX][nextY])
            {
                dfs(nextX, nextY);
            }
        }
    }
}

void bfs()
{
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty())
    {
        int curX = q.front().x;
        int curY = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextX = curX + dirMove[i].x;
            int nextY = curY + dirMove[i].y;
            if (graph[nextX][nextY] && 0 <= nextX && nextX < N && 0 <= nextY && nextY < M)
            {
                chkSurface[nextX][nextY] += 1;
            }
            if (!visited[nextX][nextY])
            {
                if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M && !graph[nextX][nextY])
                {
                    q.push({nextX, nextY});
                    visited[nextX][nextY] = true;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j])
                cheeseNum++;
        }
    }

    while (1)
    {
        if (!cheeseNum)
        {
            cout << cnt;
            return 0;
        }
        cnt++;
        bfs();
        for (int i = 1; i < N - 1; i++)
        {
            for (int j = 1; j < M - 1; j++)
            {
                if (chkSurface[i][j] >= 2)
                {
                    graph[i][j] = 0;
                    cheeseNum--;
                }
            }
        }
        memset(visited, 0, sizeof(visited));
        memset(chkSurface, 0, sizeof(chkSurface));
    }
}

```

가장 먼저 bool chk라는 함수를 만들어서 시도했었다. 하지만 배열의 최대 크기가 100*100인 상태에서 이렇게 제출하게 되면 시간초과가 났다. 때문에 chk 함수를 사용하지 않고 문제를 풀었다.

<br/>

이 문제를 풀기 위해 꽤 오랜 시간을 투자했지만 계속해서 틀리다는 답을 받았는데 그 이유는

```c++
 if (graph[nextX][nextY] && 0 <= nextX && nextX < N && 0 <= nextY && nextY < M)
 {
     chkSurface[nextX][nextY] += 1;
 }
```



바로 이 부분 때문이었다.  원래 이 부분에 대한 코드를

```c++
 if (graph[nextX][nextY])
 {
     chkSurface[nextX][nextY] += 1;
 }
```

이런 식으로 작성했었다. 내 생각에는 nextX와 nextY가 음수가 되더라도 상관없다고 생각했다. 음수가 되면 어짜피 이 if문 속으로 들어가지 못하고 또한, 그 밑에 조건문에서 걸러질 것이기 때문이다.

하지만, 현실은 그렇지 않았다.

나의 이런 코딩 스타일은 `undefined behavior` 즉, 예상치 못한 결과를 불러 일으킬 수 있는 잘못된 코딩이었다.

때문에, 다음부터 문제를 풀 때 최대한 조건들을 까다롭게 두는 것이 중요하다는 생각이 많이 들었다.