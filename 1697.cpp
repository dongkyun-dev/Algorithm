#include <iostream>
#include <queue>

using namespace std;

const int MAX=100001;
bool visited[MAX];
int N,K;

void bfs(){
    queue<pair<int, int> >q;
    q.push(make_pair(N,0));
    visited[N]=true;
    while(!q.empty()){
        int nextLocation=q.front().first;
        int seconds=q.front().second;
        q.pop();
        if(nextLocation==K){
            cout<<seconds<<"\n";
        }
        if(nextLocation+1<MAX&&0<=nextLocation&&!visited[nextLocation+1]){
            q.push(make_pair(nextLocation+1,seconds+1));
            visited[nextLocation+1]=true;
        }
        if(nextLocation-1<MAX&&0<=nextLocation-1&&!visited[nextLocation-1]){
            q.push(make_pair(nextLocation-1, seconds+1));
            visited[nextLocation-1]=true;
        }
        if(nextLocation*2<MAX&&0<=nextLocation*2&&!visited[nextLocation*2]){
            q.push(make_pair(nextLocation*2,seconds+1));
            visited[nextLocation*2]=true;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>K;
    bfs();
}