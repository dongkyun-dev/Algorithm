/**************
 parametric search라고도 부르는 이분 탐색을 통해 최솟값 혹은
 최댓값을 구해내는 문제.
 *************/

#include <iostream>

using namespace std;

long long length[10000];
long long k,n;

bool chk(int mid){
	long long count=0;
	for(int i=0;i<k;i++)
	count+=length[i]/mid;
	return count>=n;	
} //이 bool함수를 만드는 것이 중요!

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>k>>n;
	long long max=0;
	for(int i=0;i<k;i++)
	{
		cin>>length[i];
		if(max<length[i])
		max=length[i];
	}
	long long left = 1;  //만약 left를 0으로 해버리면 mid가 0이되어 런타임 에러가 발생할 수 잇다. 
	long long right = max;
	long long ans = 0;
	while(left<=right)
	{
		long long mid=(left+right)/2;
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