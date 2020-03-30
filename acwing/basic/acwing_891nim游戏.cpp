#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    int t = 0;
    while (n -- )
    {
        int x;
        cin >> x;
        t ^= x;
    }
    
    if (t) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}