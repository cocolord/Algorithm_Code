#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int v[N], w[N], s[N];

int f[N];

int main()
{
    int n, m;
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ ) cin >> w[i] >> v[i] >> s[i];
    for(int i = 1;i<=n;i++){
        for(int j = m;j>=w[i];j--){
            for(int k = 0;k <= s[i] && k * w[i] <= j;k++){
                f[j] = max(f[j],f[j-k*w[i]] + k*v[i]);
            }
        }
    }
    cout << f[m] << endl;
    
    return 0;
}