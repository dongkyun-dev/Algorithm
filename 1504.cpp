/**********
다익스트라의 새로운 예제

**********/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX=801; //vertex의 개수
const int INF=987654321;
vector<pair<int,int> > graph[MAX]; //각 vertex에서 다른 vertex로 가는 최소거리를 담은 배열

vector<int> dijkstra(int start, int vertex)
{
    vector<int> dis(vertex, INF);
    dis[start]=0;
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,start));  
    while(!pq.empty())
    {
        int distance=-pq.top().first;
        int current=pq.top().second; //짧은 것이 먼저 오도록 음수화
        pq.pop();
        if(dis[current]<distance) continue; //최단거리가 아닌 경우 스킵
        for(int i=0;i<graph[current].size();i++)
        {
            int next=graph[current][i].first; //선택된 노드의 인접노드
            int nextDistance=distance+graph[current][i].second;
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
    int vertex, edge;
    cin>>vertex>>edge;
    vertex++;
    for(int i=0;i<edge;i++)
    {
        int start,end,weight;
        cin>>start>>end>>weight;
        graph[start].push_back(make_pair(end,weight)); //start_vertex에서 end_vertex로 가는 weight를 저장
        graph[end].push_back(make_pair(start,weight)); //end_vertex에서 start_vertex로 가는 weight를 저장
    }
    int mustPassingNode1, mustPassingNode2;
    cin>>mustPassingNode1>>mustPassingNode2;

    vector<int> result_of_1=dijkstra(1,vertex);
    vector<int> result_of_mustPassingNode1=dijkstra(mustPassingNode1,vertex);
    vector<int> result_of_mustPassingNode2=dijkstra(mustPassingNode2,vertex);

    int tmp1=result_of_1[mustPassingNode1]+result_of_mustPassingNode1[mustPassingNode2]+result_of_mustPassingNode2[vertex-1]; //1-->mustPassingNode1-->mustPassingNode2-->vertex로 가는 경우(vertex-1을 하는 이유는 위에서 vertex++를 한번 했기 때문)
    int tmp2=result_of_1[mustPassingNode2]+result_of_mustPassingNode2[mustPassingNode1]+result_of_mustPassingNode1[vertex-1]; //1-->mustPassingNode2-->mustPassingNode1-->vertex로 가는 경우
    int answer=min(tmp1,tmp2);

    if(answer>=INF||answer<0)
    cout<<-1<<"\n";
    else
    cout<<answer<<"\n";
}

    