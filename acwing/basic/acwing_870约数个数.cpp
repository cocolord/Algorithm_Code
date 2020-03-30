#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long LL;

const int N = 110;

int n;
int mod = 1e9 + 7;

int main()
{
    cin >> n;
    
    unordered_map<int, int> primes;
    
    while (n -- )
    {
        int x;
        cin >> x;
        
        for (int i = 2; i <= x / i; i ++ )
        {
            while (x % i == 0)
            {
                x /= i;
                primes[i] ++ ;
            }
        }
        
        if (x > 1) primes[x] ++ ;
    }
    
    LL ans = 1;
    
    for (auto prime : primes)
    {
        int a = prime.first, b = prime.second;
        ans = ans * (b + 1) % mod; 
    }
    
    cout << ans << endl;
    
    return 0;
}