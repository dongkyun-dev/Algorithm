/**************
 이 문제 bfs로도 풀어보고 싶은데 못 풀겠다. 나중에 풀어봐야 할 듯.
 2667번 문제랑 똑같음. 이문제도 bfs로 풀어보고 싶은데 잘 모르겠다.
 bfs에 대한 이해가 깊어졌을 때 다시 도전해보기.
***************/
#include <iostream>
#include <vector>
#include <algorithm>
#include<string.h> //memset함수를 사용하기 위함

using namespace std;

typedef struct{
    int x,y;
}Dir;

Dir moveDir[4]={{-1,0},{1,0},{0,-1},{0,1}}; //상하좌우로만 움직일 수 있다 했음으로 움직이는 방향은 4가지만이 존재한다.

int graph[50][50];
bool visited[50][50]; //방문한 경우 기록을 남겨두어야 하기 때문에 이차원배열을 둔다.
vector<int> answer;
int cnt;
int M,N,K;

void dfs(int x, int y)
{
    cnt++;
    visited[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nextX=x+moveDir[i].x;
        int nextY=y+moveDir[i].y;
        if(0<=nextY&&nextY<N&&0<=nextX&&nextX<M) //배열의 밖 범위로 넘어가서는 안되기 때문
        {
            if(graph[nextX][nextY]==1&&visited[nextX][nextY]==false) //값이 1이면서 방문 하지 않은 경우
            {
                dfs(nextX,nextY);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>M>>N>>K;
    
    for(int i=0;i<K;i++)
    {
        int tmpX,tmpY;
        cin>>tmpX>>tmpY;
        graph[tmpX][tmpY]=1;
    }
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(graph[i][j]==1&&visited[i][j]==false)
            {
                cnt=0;
                dfs(i,j);
                answer.push_back(cnt);
            }

        }
    }
    cout<<answer.size()<<"\n";
    answer.clear();
    memset(visited,0,sizeof(visited)); //한번의 for문 이후 초기화
    memset(graph,0,sizeof(graph)); //한번의 for문 이후 초기화
    
    }
    
    
}
