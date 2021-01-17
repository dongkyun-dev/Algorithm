/************
이 문제는 bfs이지만 visited배열을 선언하지 않는다.
왜냐하면 거쳐간 경로는 바로 큐에 넣어버리기 때문에 굳이 bool 타입의 visited가 필요하지 않다.
************/
#include <iostream>
#include <queue>

using namespace std;

const int MAX=1000;
int tomato[MAX][MAX];
int result;
int N,M;
queue<pair<int,int> > q;
int notomato;
int day;

typedef struct
{
    int x,y;
}DIR;  //struct를 안쓰게 되면 밑에서 pair를 써야 하는데 pair보다는 struct를 쓰는게 편하지.

DIR moveDir[4]={ {1,0}, {-1,0}, {0,1}, {0,-1} };

bool allRipe(void)
{
    int possibleNum=N*M-notomato;
    int cnt=0;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(tomato[i][j]==1)
            cnt++;
        }
    }
    return possibleNum==cnt;
}

int bfs()
{
    int day=0;

    if(q.empty())
    return -1;

    while(!q.empty())
    {
        int currentSize=q.size();
        for(int i=0;i<currentSize;i++)
        {   
            int curX=q.front().first;
            int curY=q.front().second;
            q.pop();
            for(int j=0;j<4;j++)
            {
                int nextX=curX+moveDir[j].x;
                int nextY=curY+moveDir[j].y;

                if(0<=nextX&&nextX<M&&0<=nextY&&nextY<N&&tomato[nextX][nextY]==0)
                {
                    tomato[nextX][nextY]=1;
                    q.push(make_pair(nextX,nextY));
                }
            }
            
            if(q.size()==0&&allRipe())
            return day;
            else if(q.size()==0&&!allRipe())
            {
                return -1;
            }
            
        }
        day++;
    }    
}


int main()
{
    cin>>N>>M;
    for (int i = 0; i < M; i++)
    {
       for(int j=0;j<N;j++)
       {
           cin>>tomato[i][j]; //int tmp; cin>>tmp; maze[i][j]=tmp; 이거를 이렇게 한 줄로 줄일 수 있다.
           if(tomato[i][j]==1)
           q.push(make_pair(i,j));
           else if(tomato[i][j]==-1)
           notomato++;
       }
    }
    if(q.size()==M*N-notomato)
    {
        cout<<0;
    }
    else
    {
        cout<<bfs();
    } 
}