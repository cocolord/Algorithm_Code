#include<iostream>
#include<string.h>
using namespace std;
const int N= 110;
int w[N][N];
int dp[N][N];

int main(){
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            cin >> w[i][j];
    for(int i = 1;i<=n;i++)
        dp[1][i] = dp[1][i-1] + w[1][i];
    for(int i = 1;i<=n;i++)
        dp[i][1]=dp[i-1][1] + w[i][1];
    for(int i= 2;i<=n;i++)  
        for(int j = 2;j<=n;j++)
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + w[i][j];
    cout<< dp[n][n] <<endl;
    return 0;
}