#include<iostream>
using namespace std;

const int N = 100010;
int dp[N];
int a[N];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
        scanf("%d",&a[i]);
    dp[0] = 0;
    for(int i = 1;i<=n;i++)
        dp[i] = dp[i-1] + a[i];
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        cout<<dp[r]-dp[l-1]<<endl;    
    }
    return 0;
}