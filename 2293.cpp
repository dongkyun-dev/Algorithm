/******************
        1  2  3  4  5  6  7  8  9  10
   1    1  1  1  1  1  1  1  1  1  1
   2    0  1  1  2  2  3  3  4  4  5
   5    0  0  0  0  1  1  2  2  3  4
        1  2  2  3  4  5  5  7  8  10 

https://www.youtube.com/watch?v=2IkdAk1Loek 이 영상의 내용을 참고.
******************/
#include <iostream>

using namespace std;

int coin[101];
int dp[10001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        coin[i]=tmp;
    }
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=coin[i];j<=k;j++)
        {
            dp[j]+=dp[j-coin[i]];
        }
    }
    cout<<dp[k];

}