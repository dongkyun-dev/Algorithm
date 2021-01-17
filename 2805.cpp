/**************
 parametric search라고도 부르는 이분 탐색을 통해 최솟값 혹은
 최댓값을 구해내는 문제의 두번째.
 이전 문제와 이 문제에서 제시된 큰 틀만 기억한다면 쉽게 풀 수 있는 문제이다.
 (bool함수의 수정말고는 딱히 어려운 것이 없기 때문.)
 처음에는 모든 변수를 long long 선언했다.(21억이 넘는다 판단돼서.)
 나중에 보니 int로 해도 상관없다고 판단이 들어 모두 int로 전환했고
 이렇게 해도 런타임 에러가 나지 않는다.
 !!!굳이 long long을 쓰지 않아도 되는 곳에 long long을 쓰는 버릇을 버리자!!
 *************/

#include <iostream>

using namespace std;

int length[1000000];
int n,m;

bool chk(int mid){
	long long count=0;
	for(int i=0;i<n;i++)
	{
        if(length[i]>mid)
        count+=length[i]-mid;
    }
	return count>=m;	
} //이 bool함수를 만드는 것이 중요!

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>n>>m;
	int max=0;
	for(int i=0;i<n;i++)
	{
		cin>>length[i];
		if(max<length[i])
		max=length[i];
	}
	int left = 1;  //만약 left를 0으로 해버리면 mid가 0이되어 런타임 에러가 발생할 수 잇다. 
	int right = max;
	int ans = 0;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(chk(mid)){
			if(mid>ans)
			ans=mid;
			left=mid+1;  //count가 n보다 커지게 되어서 이 함수가 실행될 경우 자르는 길이가 더 켜져야하기 때문에 left를 mid+1로 설정한다.
		}
		else
		right=mid-1;
	}
	cout<<ans;	
}