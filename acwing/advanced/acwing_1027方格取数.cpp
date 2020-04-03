#include<iostream>
using namespace std;

const int N = 15;
int w[N][N];
int dp[2*N][N][N];

int main(){
    int n;
    cin >> n;
    int a,b,c;
    while(cin >> a >> b >> c , a && b&&c){
        w[a][b]=c;
    }
    for(int k = 2;k<=2*n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j <= n;j++){
                int i1= k - i,j1=k-j;
                //检查不能漏掉
                // if(i1>=1 && i1 <=n && j1 >= 1 && j1 <= n){
                    int t = w[i][i1];
                    if(i!=j) t += w[j][j1];
                    int &x = dp[k][i][j];
                    x = max(x,dp[k-1][i-1][j]+t) ;
                    x = max(x,dp[k-1][i][j-1]+t);
                    x = max(x,dp[k-1][i-1][j-1]+t) ;
                    x = max(x,dp[k-1][i][j] + t) ;
                // }
            }
        }
    }
    cout << dp[n+n][n][n]<<endl;
}