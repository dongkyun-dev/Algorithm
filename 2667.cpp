/**************
 이 문제 bfs로도 풀어보고 싶은데 못 풀겠다. 나중에 풀어봐야 할 듯.



***************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct{
    int x,y;
}Dir;

Dir moveDir[4]={{-1,0},{1,0},{0,-1},{0,1}}; //상하좌우로만 움직일 수 있다 했음으로 움직이는 방향은 4가지만이 존재한다.

string graph[25];
bool visited[25][25]; //방문한 경우 기록을 남겨두어야 하기 때문에 이차원배열을 둔다.
vector<int> answer;
int cnt;
int num;

void dfs(int x, int y)
{
    cnt++;
    visited[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nextX=x+moveDir[i].x;
        int nextY=y+moveDir[i].y;
        if(0<=nextY&&nextY<num&&0<=nextX&&nextX<num) //배열의 밖 범위로 넘어가서는 안되기 때문
        {
            if(graph[nextX][nextY]=='1'&&visited[nextX][nextY]==false) //값이 1이면서 방문 하지 않은 경우
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
    cin>>num;
    for(int i=0;i<num;i++)
    cin>>graph[i];
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            if(graph[i][j]=='1'&&visited[i][j]==false)
            {
                cnt=0;
                dfs(i,j);
                answer.push_back(cnt);
            }

        }
    }
    sort(answer.begin(),answer.end());
    cout<<answer.size()<<"\n";
    for(int i=0;i<answer.size();i++)
    cout<<answer[i]<<"\n";
}
