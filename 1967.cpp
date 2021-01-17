/**************************************
 항상 graph 배열은 int graph[MAX][MAX]의 모양으로 설정해왔다.
 하지만 이 문제에서는 그렇게 하면 메모리 초과가 나버린다.
 그래서 필요한 만큼의 크기의 배열만 제공하는 vector를 사용하는 것이다.
 앞으로 dfs bfs 문제를 풀 때 메모리를 신경쓰기 위해서는 단순한 배열로 graph를
 선언하는 것보다는 vector로 선언하여 배열의 크기를 최소화 시키는 것이 좋겠다.

 이 문제에서 bfs가 아닌 dfs를 쓴 이유는 root로 부터 가장 멀리 있는 노드는
 가장 낮은 높이에 있는 노드이기 때문이다. 너비가 아닌 깊이 탐색이 진행되기 때문에
 dfs를 쓰는 것이 합리적이다. 

 트리의 지름을 구하는 문제는 
 1.root로 부터 가장 먼 노드를 찾고 
 2.그 노드로 부터 또 가장 먼 노드를 찾으면
 3.이 두 노드 사이의 거리가 지름이 된다.

 이 두 노드는 항상 트리에서 가장 낮은 높이에 위치하게 된다.(dfs를 쓰는 이유)
 이거를 뭐 증명하던데 그냥 그렇다고 믿자.
***************************************/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX=10001;

int N;
bool visited[MAX];
//int graph[MAX][MAX];
vector<pair<int, int> >graph[MAX];
/*vector<int> graph는 결국 int graph[] 와 같은 배열을 선언한 거랑 다름이 없지
따라서 vector<int> graph[MAX]는 int graph[MAX][MAX]와 같은 2차원 배열을 선언한 것과 동일
*/
int diameter;
int farthestNode;

void DFS(int node, int cost){

    if(visited[node])
    return; //기저사례 방문했던 곳은 다시 방문하지 않는다.
    visited[node]=true;
    if(diameter<cost){ //최대의 지름을 찾아야 하기 때문.
        diameter=cost;
        farthestNode=node;
    }
    
    for(int i=0;i<graph[node].size();i++){
       DFS(graph[node][i].first, cost+graph[node][i].second);
    }
   /* 
   for(int i=1;i<=N;i++){
       if(graph[node][i])
       DFS(i, cost+graph[node][i]);
   }
   */
}

int main(){
    cin>>N;
    for(int i=1;i<N;i++){
        int node1, node2, cost;
        cin>>node1>>node2>>cost;
        graph[node1].push_back(make_pair(node2, cost));
        graph[node2].push_back(make_pair(node1, cost));
        /*만약 int i=1이라면 
        graph[node1][1].first=node2;
        graph[node1][1].second=cost;
        graph[node2][1].first=node1;
        graph[node2][1].second=cost;
        이런 모양이 되겠지
        */
        //graph[node1][node2]=cost;
        //graph[node2][node1]=cost;
    }
    memset(visited, false, sizeof(visited));
    DFS(1,0); //root로 부터 가장 먼 노드를 찾는다.
    memset(visited, false, sizeof(visited));
    diameter=0;
    DFS(farthestNode,0); //root로 부터 가장 먼 노드에서 또 가장 먼 노드를 찾는다.

    cout<<diameter<<"\n";

}