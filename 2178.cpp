/************
기본적으로 최단거리를 구하는 문제는 bfs로 풀어야한다.
dfs도 가능하지만 dfs의 경우 모든 경우를 체크하기 때문에 시간이 너무 걸려.
************/
#include <iostream>
#include <queue>

using namespace std;

const int MAX=100;
int maze[MAX][MAX];
bool visited[MAX][MAX];
int result;
int N,M;

typedef struct
{
    int x,y,length;
}DIR;  //struct를 안쓰게 되면 밑에서 pair를 써야 하는데 pair보다는 struct를 쓰는게 편하지.

void bfs(int x, int y, int length)
{
    queue<DIR> q;
    DIR start={x,y,length};
    q.push(start);

    while(!q.empty())
    {
        int curX=q.front().x;
        int curY=q.front().y;
        int curLength=q.front().length;
        q.pop();
        visited[x][y]=true;
        //단순히 x를 x좌표 y를 y좌표라고 생각하면 헷갈려.
        //x는 행 y는 열이라고 생각하면 편해.
        if(curX==N-1&&curY==M-1)
        {
            result=curLength;
            break;
        }
        if(curY+1<M&&maze[curX][curY+1]&&!visited[curX][curY+1])
        {
            DIR East={curX,curY+1,curLength+1};
            visited[curX][curY+1]=true;
            q.push(East);
        }
        if(curY-1>=0&&maze[curX][curY-1]&&!visited[curX][curY-1])
        {
            DIR West={curX,curY-1,curLength+1};
            visited[curX][curY-1]=true;
            q.push(West);
        }
        if(curX+1<N&&maze[curX+1][curY]&&!visited[curX+1][curY])
        {
            DIR South={curX+1,curY,curLength+1};
            visited[curX+1][curY]=true;
            q.push(South);
        }
        if(curX-1>=0&&maze[curX-1][curY]&&!visited[curX-1][curY])
        {
            DIR North={curX-1,curY,curLength+1};
            visited[curX-1][curY]=true;
            q.push(North);
        }

    }    
}


int main()
{
    cin>>N>>M;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
        maze[i][j] = temp[j]-'0';
    }
    //내가 처음에 여기에서 이중 roop로 maze를 채우려 했었어.
    //근데 숫자들 사이에 빈칸이 없기 때문에 이런 식으로 받아버리면
    //안돼. 마지막에 문자 0을 빼는 이유는 저렇게 하면 char 형태를 int 형태로 전환시킬 수 있기 때문.
    bfs(0,0,1);
    cout<<result;
    
}