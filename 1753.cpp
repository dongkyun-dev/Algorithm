/******************
다익스트라 기본

https://panty.run/array-size-const/
--->처음에 정점의 개수를 int number=20001; 로 했는데 계속해서 오류가 났음.
알고보니 배열의 크기에는 정확한 상수값이 와야 했음. 그래서 int number=20001; vector<pair<int,int>> a[number]; 는 오류가 날 수 밖에 없었다.
이를 해결하기 위해서는 const int number=20001; 로 선언하던가 #define number 20001 로 선언했어야 한다.
******************/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int number=20001; //정점의 개수
const int INF=987654321; 
int V,E;

vector<pair<int, int> > a[number];


vector<int> dijkstra(int start, int vertex)
{
    vector<int> dis(vertex, INF);
    dis[start]=0;
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,start));  
    /**********************
     이 윗부분!!!! pair의 정렬 우선순위는 first가 갖는다. 나는 계속 make_pair(start,0);으로 했는데 시간초과가 되었다고 자꾸 나왔었음. 
    내가 한대로 하면 모든 경우를 훑고 정렬이 되기 때문이라고 한다. make_pair(0,start);로 해야만 최단거리만 탐방해서 걸리는 시간이 적어진다.
    근데, 이해가 되지 않음. 아마도 우선순위 큐에 대한 이해가 부족하던지 다익스트라에 대한 이해가 부족해서 그런 것 같다. 조금 더 이해한 이후에 다시 이부분을 
    생각해봐야겠다.
    *************************/
    while(!pq.empty())
    {
        int distance=-pq.top().first;
        int current=pq.top().second; //짧은 것이 먼저 오도록 음수화
        pq.pop();
        if(dis[current]<distance) continue; //최단거리가 아닌 경우 스킵
        for(int i=0;i<a[current].size();i++)
        {
            int next=a[current][i].first; //선택된 노드의 인접노드
            int nextDistance=distance+a[current][i].second;
            if(nextDistance<dis[next])
            {
                dis[next]=nextDistance;
                pq.push(make_pair(-nextDistance,next));
            }
             
        }
    }
    return dis;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i;
    cin>>V>>E;
    cin>>i;
    V++;
    for(int i=0;i<E;i++)
    {
        int num1,num2,num3;
        cin>>num1>>num2>>num3;
        a[num1].push_back(make_pair(num2,num3));
    }
   
    vector<int> result = dijkstra(i,V);
    for(int i=1;i<V;i++)
    {
        if(result[i]==INF)
        cout<<"INF"<<"\n";
        else
        {
            cout<<result[i]<<"\n";
        }
        
    }
    

}