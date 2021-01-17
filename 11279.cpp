/****************
 그냥 우선순위큐 문제
 그다지 어렵지 않다. 그냥 priority queue를 알고만 있으면 됨.
 ****************/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin>>num;
    priority_queue<int> pq;  //우선순위 큐의 생성
    for(int i=0;i<num;i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp>0)
        pq.push(tmp);
        else if(tmp==0)
        {
            if(!pq.empty())
            {
                cout<<pq.top()<<"\n";
                pq.pop();
            }
            else
            {
                cout<<0<<"\n";
            }
            
        }
    }
}