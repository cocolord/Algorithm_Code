#include<cstring>
#include<iostream>
using namespace std;
const int N = 1010;
int a[N][N];
int dp[N][N]={0};
int n;

int main(){
    cin >> n;
    memset(dp,-0x3f3f3f3f,sizeof dp);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            cin >> a[i][j];
        }
    }
    dp[1][1] = a[1][1];
    int ret = -0x7ffffff;
    for(int i = 2;i <= n ; i++){
        for(int j = 1;j <=i ;j++){
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + a[i][j];
        }
    }
    for(int i = 1;i<=n;i++) ret = max(ret,dp[n][i]);
    cout << ret << endl;
    return 0;
}