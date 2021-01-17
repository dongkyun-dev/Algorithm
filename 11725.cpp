#include <iostream>
#include <vector>

using namespace std;

const int MAX=100000+1; //항상 주어진 최고 큰 int의 경우보다 하나 크게. const 선언이 된 변수는 항상 대문자와 밑줄(_)로만 이름이 이루어져야 한다.

int num;
bool visited[MAX];
vector<int> tree[MAX];
int parent[MAX];

void dfs(int x)
{
    if(visited[x]) return;
    visited[x]=true;
    for(int i=0;i<tree[x].size();i++)
    {
        int y=tree[x][i]; //연결되어 있는 번호들을 확인하고 만약에 방문하지 않았다면 그 번호가 자식이 된다.
        if(!visited[y])
        {
            parent[y]=x;
            dfs(y);
        }
        
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>num;
    for(int i=0;i<num-1;i++)
    {
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        tree[tmp1].push_back(tmp2);
        tree[tmp2].push_back(tmp1);
    }

    dfs(1);
    for(int i=2;i<=num;i++)
    cout<<parent[i]<<"\n";
}