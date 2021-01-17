#include <iostream>
#include <string.h>

using namespace std;

const int MAX=21;

bool visited[MAX];
int M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>M;
    for(int i=0;i<M;i++){
        string tmp;
        cin>>tmp;
        if(tmp=="add"){
            int num;
            cin>>num;
            visited[num]=true;
        }
        else if(tmp=="remove"){
            int num;
            cin>>num;
            visited[num]=false;
        }
        else if(tmp=="check"){
            int num;
            cin>>num;
            if(visited[num])
            cout<<1<<"\n";
            else
            cout<<0<<"\n";
        }
        else if(tmp=="toggle"){
            int num;
            cin>>num;
            if(visited[num])
            visited[num]=false;
            else
            visited[num]=true;
        }
        else if(tmp=="all"){
            memset(visited, true, sizeof(visited));
        }
        else{
            memset(visited, false, sizeof(visited));
        }
    }

}