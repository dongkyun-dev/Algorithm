/************
여기서 이동할 수 있는 경우는 단 두가지.
1. 방문한 적이 없는 곳이면서(visited가 0이다), 방문 할 수 있는 곳(graph가 0이다)
2. 방문한 적이 없는 곳이면서(visited가 0이다) 방문 할 수 없는 곳이지만(graph가 1이다) 아직 벽을 부술 수 있는 기회가 남아있다(3차원 배열 visited의 마지막이 1이다)


맨 아래에 주석으로 단 부분은 visited를 2차원 배열로 만들고 bool 타입의 check를 따로 두어서 벽을 부수는지 체크해보려했다.
실패함.----> 왜냐하면 내 위치에서 갈 수 있는 방향은 4가지. 만약에 bool 타입으로 check를 따로 두게 되면 한쪽 벽면을 부순다면 다른 쪽 벽면을 부수는 경우를 확인 할 수 없어진다.
check를 바로 true로 바꿔버리기 때문.
************/
#include <iostream>
#include <queue>

using namespace std;

const int MAX=1001;
int graph[MAX][MAX];
int N,M;
int visited[MAX][MAX][2]; //벽을 깨는 한 번의 기회를 주기 위해 3차원 배열로 선언한다.

typedef struct{
    int x, y;
}DIR;

DIR moveDir[4]={ {-1,0}, {1,0}, {0,1}, {0,-1}};

void bfs(){
    queue<pair<pair<int, int>,int> >q;
    q.push(make_pair(make_pair(0,0),1)); //벽을 깨는 기회 1번이 주어진다.
    visited[0][0][1]=1;
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int block=q.front().second;
        q.pop();

        if(x==N-1&&y==M-1){
            cout<<visited[x][y][block];
            return;
        }
        for(int i=0;i<4;i++){
            int nextX=x+moveDir[i].x;
            int nextY=y+moveDir[i].y;
            if(nextX>=0&&nextX<N&&nextY>=0&&nextY<M&&block==1&&graph[nextX][nextY]==1&&visited[nextX][nextY][block]==0){ //벽을 깬 적이 없고 벽이 앞에 있다면!
                visited[nextX][nextY][block-1]=visited[x][y][block]+1;
                q.push(make_pair(make_pair(nextX, nextY),block-1));
            }
            else if(nextX>=0&&nextX<N&&nextY>=0&&nextY<M&&graph[nextX][nextY]==0&&visited[nextX][nextY][block]==0){ //벽이 존재하지 않고 벽을 부순 적이 없으면서 방문한 적이 없는 곳이라면!
                visited[nextX][nextY][block]=visited[x][y][block]+1;
                q.push(make_pair(make_pair(nextX, nextY),block));

            }
        }
    }
    cout<<-1;
}


int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string tmp;
        cin>>tmp;
        for(int j=0;j<M;j++){
            graph[i][j]=tmp[j]-'0';
        }
    }
    bfs();
}
/************
#include <iostream>
#include <queue>
using namespace std;
const int MAX=1001;
int graph[MAX][MAX];
int N,M;
int visited[MAX][MAX];
bool check;
typedef struct{
    int x, y;
}DIR;
DIR moveDir[4]={ {-1,0}, {1,0}, {0,1}, {0,-1}};
void bfs(){
    queue<pair<int, int> >q;
    q.push(make_pair(0,0));
    visited[0][0]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==N-1&&y==M-1){
            cout<<visited[x][y];
            return;
        }
        for(int i=0;i<4;i++){
            int nextX=x+moveDir[i].x;
            int nextY=y+moveDir[i].y;
            if(nextX>=0&&nextX<N&&nextY>=0&&nextY<M&&!check&&graph[nextX][nextY]==1){
                visited[nextX][nextY]=visited[x][y]+1;
                check=true;
                q.push(make_pair(nextX, nextY));
            }
            else if(nextX>=0&&nextX<N&&nextY>=0&&nextY<M&&graph[nextX][nextY]==0&&visited[nextX][nextY]==0){
                visited[nextX][nextY]=visited[x][y]+1;
                q.push(make_pair(nextX, nextY));
            }
        }
    }
    cout<<-1;
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string tmp;
        cin>>tmp;
        for(int j=0;j<M;j++){
            graph[i][j]=tmp[j]-'0';
        }
    }
    bfs();
}
*********************/