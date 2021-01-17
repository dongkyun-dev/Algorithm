/**************
 parametric search라고도 부르는 이분 탐색을 통해 최솟값 혹은
 최댓값을 구해내는 문제의 세번째 예제.
 이 문제가 parametric 문제 예제 중에서 가장 보기 좋은 문제 인 듯.
 어렵지만 이해하고 넘어갈 수 있는 부분이 많고 생각해야 할 부분이 많다.
 *************/

#include <iostream>
#include <algorithm>

using namespace std;

int length[200000];
int n,c;

bool chk(int mid){
	int count=1;  //첫집에 공유기를 설치한다 가정.
    int prev=length[0];
	for(int i=1;i<n;i++) //첫 집에 이미 공유기가 설치되었기에 i는 1부터 시작한다.
	{
        if(length[i]-prev>=mid)  //mid는 첫 x좌표와 마지막 x좌표의 중간 
        {
            count++;
            prev=length[i];  //비교할 때 계속해서 붙어있는 집 사이의 거리를 조회한다.
        }
    }
	return count>=c;	
} //이 bool함수를 만드는 것이 중요!

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>n>>c;
	for(int i=0;i<n;i++)
	{
		cin>>length[i];
	}
    sort(length,length+n);
	int left = 1;  //만약 left를 0으로 해버리면 mid가 0이되어 런타임 에러가 발생할 수 잇다. 
	int right = length[n-1]-length[0];
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

/*********************
결국!!! mid를 잡아놓고 집 간의 거리가 mid를 넘는 경우의 총 횟수가 제시된 c를 넘을 경우
mid를 늘려나가는 것이고 집 간의 거리가 mid를 넘는 경우의 총 횟수가 제시된 c를 넘지 못한 경우
mid를 줄여 나가는 것이다.
잘 봐둬야 하는 문제이다.
********************/


