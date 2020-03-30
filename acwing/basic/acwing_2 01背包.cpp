#include<iostream>
using namespace std;
const int N = 1010;
int wei[N],val[N];
int dp[N][N];
int main(){
    int n,v;
    cin >> n >> v;
    for(int i = 1;i<=n;i++)
        cin>>wei[i]>>val[i];
    for(int i =1  ;i <=n;i++){
        for(int j =0 ;j <= v ;j++){
            dp[i][j] = dp[i-1][j];
            if(wei[i] <= j ){
                dp[i][j] = max(dp[i][j],dp[i-1][j-wei[i]] + val[i]);
            }
        }
    }
    cout << dp[n][v]<<endl;
    return 0;
}