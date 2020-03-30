#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

const int N = 110;

vector<int> get_dividors(int n)
{
    vector<int> ans;
    for (int i = 1; i <= n / i; i ++ )
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if (i != n / i) ans.push_back(n / i);
        }
    }
    
    sort(ans.begin(), ans.end());
    
    return ans;
}

int main()
{
    int n;
    cin >> n;
    
    while (n -- )
    {
        int x;
        cin >> x;
        
        vector<int> ans;
        ans = get_dividors(x);
        for (int i = 0; i < ans.size(); i ++ ) cout << ans[i] << " ";
        cout << endl;
    }
    
    
    return 0;
}