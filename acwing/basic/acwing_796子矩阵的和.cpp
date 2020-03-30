#include<iostream>
using namespace std;

const int N = 1010;
int dp[N][N];
int a[N][N];

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
            scanf("%d",&a[i][j]);
    // for(int i = 0;i<n;i++)
    //     dp[i][0] = dp[i][m+1] = 0;
    // for(int j = 0;j<m;j++)
    //     dp[0][j]=dp[n+1][j]= 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1] + a[i][j];
        }
        // dp[i+1][0] = dp[i][m];
    }
    while (q--)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<dp[x2][y2]-dp[x1-1][y2] -dp[x2][y1-1]+dp[x1-1][y1-1] <<endl;
    }
    return 0;
}