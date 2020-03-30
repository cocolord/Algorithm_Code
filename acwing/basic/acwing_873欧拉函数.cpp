#include <iostream>

using namespace std;

// int phi(int x)
// {
//     int res = x;
//     //分解质因数,然后用欧拉函数公式来计算
//     //phi(n) = n pi( 1 - 1/p_i)
//     for (int i = 2; i <= x / i; i ++ )
//     {
//         if (x % i == 0)
//         {
//             res = res / i * (i - 1);
//             while (x % i == 0) x /= i;
//         }
//     }
//     if (x > 1) res = res / x * (x - 1);
    
//     return res;
// }
int phi(int x){
    int ret = x;
    for(int i=2 ;i<=x/i;i++){
        if(x % i == 0){
            ret = ret / i * (i - 1);
            while(x%i==0) x/=i;
        }
    }
    //大于1 说明还有一个质因子
    if(x > 1) ret = ret / x *(x-1);
    return ret;

}
int main()
{
    int n;
    cin >> n;
    while (n -- )
    {
        int x;
        cin >> x;
        cout << phi(x) << endl;
    }
    
    return 0;
}