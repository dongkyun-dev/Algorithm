/**********
기본적인 유니온파인드. 유니온 파인트 함수들은 아예 수정조차 하지 않았다.

**********/
#include <iostream>

using namespace std;

int N, M;
int parent[200];

int getParent(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = getParent(parent[x]);
    //재귀함수를 통해 연결되있는 그래프에서의 가장 작은 vertex를 찾는다. 결국 이 vertex 값이 같다면 같은 그래프에 속한다고 할 수 있다.
}

void unionParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    if (a < b)
        parent[b] = a;
    else if (a > b)
        parent[a] = b;
    //a와 b 중 더 작은 값을 상대의 부모에 넣게 된다.
}

int findParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    if (a == b)
        return 1;
    else
        return 0;
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int num;
            cin >> num;
            if (num == 1)
                unionParent(i, j);
        }
    }
    int start;
    cin >> start;
    int root = getParent(start); //첫번째 입력의 root를 확인하고
    for (int i = 1; i < M; i++)  //다른 입력들의 root가 첫번째 입력의 root값과 같은지를 확인한다.
    {
        int tmp;
        cin >> tmp;
        if (root != getParent(tmp))
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}