/*************
플로이드-워셜 알고리즘(Floyd-Warshall Algorithm)은 그래프에서 모든 꼭짓점 
사이의 최단 경로의 거리를 구하는 알고리즘이다. 음수 가중치를 갖는 간선도 순환만
없다면 잘 처리된다. 제일 바깥쪽 반복문은 거쳐가는 꼭짓점이고, 두 번째 반복문은 
출발하는 꼭짓점, 세 번째 반복문은 도착하는 꼭짓점이다. 이 알고리즘은 플로이드 
알고리즘이라고도 알려져 있다.

시간 복잡도는 O(n^3)

기본적으로 from-->to 보다 from-->via + via-->to 가 짧은 경우를 찾는 것이다.

**************/
#include <iostream>

using namespace std;

const int MAX=101;
int N,M;
int graph[MAX][MAX];

void floyd(){
    for(int via=1;via<=N;via++){
        for(int from=1;from<=N;from++){
            if(graph[from][via]==0) //결국에 from-->via 와 via-->to의 합이 from-->to보다 작은 지를 확인하는 건데 이게 0이라면 roop를 안 돌려도되지.
            continue;
            for(int to=1;to<=N;to++){
                if(from==to||graph[via][to]==0)
                continue;
                if(graph[from][to]==0||graph[from][to]>graph[from][via]+graph[via][to])
                graph[from][to]=graph[from][via]+graph[via][to];
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int from, to, cost;
        cin>>from>>to>>cost;
        if(!graph[from][to]){
            graph[from][to]=cost;
        }
        else{
            graph[from][to]=min(graph[from][to],cost);
        }
    }
    floyd();

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
}