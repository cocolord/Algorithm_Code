#include<iostream>
using namespace std;
const  int N = 1010;
int w[N][N];
int dp[N][N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int r,c;
        cin >> r >> c;
        for(int i = 1;i<=r;i++){
            for(int j = 1;j<=c;j++){
                cin >> w[i][j];
            }
        }
        for(int i = 1;i<=r;i++){
            for(int j = 1;j<=c;j++){
                dp[i][j] = max(dp[i-1][j] + w[i][j],dp[i][j-1]+w[i][j]);
            }
        }
        cout<<dp[r][c]<<endl;
    }
}