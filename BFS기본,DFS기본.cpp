/***************
          1
        /   \
      2 ------3
     / \     / \    
    4---5   6---7

    이런 모양의 이진 트리가 있다고 가정했을 때의 bfs  
****************/

/***************
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number=4;
bool c[4]; //방문했는지 체크하는 배열
vector<int> a[5]; //첫 인덱스의 시작이 0이 아닌 1로 하기 위해서 8 크기의 벡터 생성

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    c[start]=true;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        cout<<x;
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
    a[1].push_back(2);
    a[2].push_back(1);

    a[1].push_back(3);
    a[3].push_back(1);

    a[1].push_back(4);
    a[4].push_back(1);

    a[2].push_back(4);
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    a[3].push_back(6);
    a[6].push_back(3);
    
    a[3].push_back(7);
    a[7].push_back(3);

    a[4].push_back(5);
    a[5].push_back(4);

    a[6].push_back(7);
    a[7].push_back(6);

    bfs(1);
}

**********************/

#include <iostream>
#include <vector>

using namespace std;

int number=7;
bool c[7];
vector<int> a[8];

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

int main()
{
    a[1].push_back(2);
    a[2].push_back(1);

    a[1].push_back(3);
    a[3].push_back(1);

    a[1].push_back(4);
    a[4].push_back(1);

    a[2].push_back(4);
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    a[3].push_back(6);
    a[6].push_back(3);
    
    a[3].push_back(7);
    a[7].push_back(3);

    a[4].push_back(5);
    a[5].push_back(4);

    a[6].push_back(7);
    a[7].push_back(6);

    dfs(1);
}