/****************
 우선순위 큐에서의 pair 사용!!!
 
 제일 중요한 것은 만약 우선순위 큐에서 pair를 사용한다면 어떤 값을 기준으로 정렬하냐??가 제일 의문
 -만약 자료형에 pair가 들어간다면 pair<a, b>일 때, a의 값이 같다면 b의 값에 따라 우선순위가 결정된다.
 따라서 이 문제의 경우 절대값이 a에 들어감으로 똑같은 순위를 가지지만 b에서 원래의 값이 그대로 들어오게 되면서 음수 또한 오름차순으로 정렬되게 된다.

 -기본적으로 우선순위 큐의 push 또는 pop을 할 때 시간복잡도는 logN 이다.!!!!
 ***************/
#include <iostream>
#include <algorithm>       //절대값(abs)을 사용하기 위한 헤더 파일
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;  //꺽새가 두 개 이상 붙을 경우 각 꺽새 사이에 띄어쓰기를 추가한다는 것을 명심하자.
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp!=0)
        {
            pq.push(make_pair(abs(tmp),tmp));
        }
        else if(tmp==0)
        {
            if(!pq.empty())
            {
                cout<<pq.top().second<<"\n";
                pq.pop();
            }
            else
            {
                cout<<0<<"\n";
            }
            
        }
    }
}