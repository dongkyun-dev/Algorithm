/***********
maxheap과 minheap을 사용하는 문제. 이 문제를 풀기 위한 3가지 조건

1. 최소 힙의 값들은 모두 최대 힙보다 크도록하고

2. 최대 힙의 크기가 최소 힙의 크기보다 1 크거나 같도록 유지하며 값을 넣는다.

3. 값을 넣어준 후 최대 힙과 최소 힙의 top 값을 비교해서 최소 힙의 top보다 최대 힙의 top이 더 크다면 값을 교환해준다.

그러면 최대 힙의 top값이 중간값이 된다

이해하기 쉽게 설명하자면 이 힙이 배열에 있다고 가정하자. 여기서 가운데에 있는
수를 꺼내기 위한 가장 쉬운 방법은 배열을 절반으로 쪼개는 것. 중앙을 쪼개서 사람 인자로
만들어 놓으면 왼쪽은 maxheap(내림차순) 오른쪽은 minheap(오름차순)의 구조를 띄게 된다.
배열 내부의 개수가 짝수 개인 경우 작은 것을 꺼내라 했기 때문에 항상 maxheap의 top을 꺼내게 된다.
배열의 구조를 만들기 위해 1번과 3번 같은 조건을 걸어둔 것이다.
***********/
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
    priority_queue<int> maxheap;//내림차순 사람 인의 왼쪽 부분
    priority_queue<int, vector<int>, greater<int> > minheap; //오름차순 사람 인자의 오른쪽 부분
    for(int i=0;i<num;i++)
    {   
        int tmp;
        cin>>tmp;
        if(maxheap.size()==minheap.size()) //2번 조건. 둘 다 비어 있을 경우 maxheap이 우선이다.
        maxheap.push(tmp);
        else
        minheap.push(tmp);

        if(!maxheap.empty()&&!minheap.empty()&&maxheap.top()>minheap.top()) //1번 조건, 3번 조건을 만족시키기 위한 조건문!! 우선순위 큐의 특징상 계속 정렬이 되기 때문에 top의 값만 비교해주면 된다.
        {
            int maxheaptmp=maxheap.top();
            int minheaptmp=minheap.top();
            maxheap.pop(); minheap.pop();
            maxheap.push(minheaptmp);
            minheap.push(maxheaptmp);
        }

        cout<<maxheap.top()<<"\n";
        

    }
}