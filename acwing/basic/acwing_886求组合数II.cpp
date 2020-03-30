#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long LL;

const int N = 100010;
const int mod = 1e9 + 7;
int n;

LL fact[N], infact[N];

LL qmi(LL a, int k, int p)
{
    LL res = 1;
    while (k)
    {
        if (k & 1) res = res * a % p;
        k >>= 1;
        a = a * a % mod;
    }
    
    return res;
}

int main() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i ++ ) fact[i] = fact[i - 1] * i % mod;
    for (int i = 1; i < N; i ++ ) infact[i] = infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    cin >> n;
    
    while (n -- )
    {
        int a, b;
        cin >> a >> b;
        
        cout << fact[a] * infact[b] % mod * infact[a - b] % mod  << endl;
    }
    
    return 0;
}