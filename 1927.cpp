/***********
 우선 순위 큐 문제.
 priority queue를 어떤식으로 선언하냐에 대한 문제이다.
 우리가 기본적으로 선언하는 priority_queue<int> pq;의 구조를 보게 되면
 priority_queue<int, vector<int>, less<int> > pq;의 형식 이 less라는 놈 때문에 내림차순으로 자동 정렬되게 된다.
 만약 내가 less 대신 greater을 쓰게 된다면 우선순위 큐를 쓰면서 오름차순 정렬을 할 수 있게 된다.
 제일 중요한건 less int 뒤에 꺽새 두 개 인데, 이 두 개를 붙여쓰게 되면 에러가 나게 된다.(operator로 인식해서 인 듯?)
 따라서 이 두 개의 꺽새를 반드시 띄어서 적어야 한다.
 ***********/ 

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int,vector<int>,greater<int> > pq;  //꺽새 두 개를 반드시 띄어서 적는다.
    int num;
    cin>>num;
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