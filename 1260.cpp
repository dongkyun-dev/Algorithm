#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N,M,V;
bool c[10000]; //방문했는지 체크하는 배열
vector<int> a[10001]; //첫 인덱스의 시작이 0이 아닌 1로 하기 위해서 8 크기의 벡터 생성

void dfs(int x)
{
    if(c[x]) return;
    c[x]=true;
    cout<<x<<" ";
    for(int i=0;i<a[x].size();i++)
    {
        int y=a[x][i];
        dfs(y);
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    c[start]=true;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        cout<<x<<" ";
        for(int i=0;i<a[x].size();i++)
        {
            int y=a[x][i];
            if(!c[y])
            {
                q.push(y);
                c[y]=true;
            }
        }
    }
}

int main()
{
    cin>>N>>M>>V;
    for(int i=0;i<M;i++)
    {
        int start,end;
        cin>>start>>end;
        a[start].push_back(end);
        a[end].push_back(start);
    }
    for(int i=0;i<M;i++)
    {
        sort(a[i].begin(),a[i].end()); //오름차순으로 입력이 들어오는 것이 아니기 때문에 순회 전 정렬을 한번 해주어야한다.
    }
    dfs(V);
    memset(c,0,sizeof(c)); //한번의 dfs 순회 이후 다시 c 배열을 false로 바꾸어주어야 하기 때문. memset 함수 사용을 위해서는 string.h를 포함한다.
    cout<<"\n";
    bfs(V);
}