#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 110;
int v[N],w[N];
int dp[N];
int n,m;
int main(){
    cin >> n >> m;
    for(int i= 0;i < n;i++){
        int s;
        cin >> s;
        for(int j = 0;j < s;j++) cin >> w[j] >> v[j];
        for(int j = m;j >= 0;j--){
            for(int k = 0;k<s;k++){
                if(w[k] <= j ){
                    dp[j] = max(dp[j],dp[j-w[k]] + v[k]);
                }
            }
        }
    }
    cout << dp[m]<<endl;
    return 0;
}