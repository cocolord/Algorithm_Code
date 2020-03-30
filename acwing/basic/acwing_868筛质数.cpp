#include <iostream>
using namespace std;
const int N = 1e6+10;
//第几个素数
int prime[N], cnt;
//素数的倍数们
bool st[N];

//朴素筛法-O(nlogn)
void get_primess(int n) {
    for(int i = 2; i <= n; i++) {
        if(!st[i]) prime[cnt++] = i;
        for(int j = i+i; j <= n; j += i) 
            st[j] = true;
    }
}

//埃式筛法-O(nloglogn)
void get_primes(int n) {
    for(int i = 2; i <= n; i++) {
        if(!st[i]){ 
            prime[cnt++] = i;
            for(int j = i; j <= n; j += i)
                st[j] = true;
        }
    } 
}

// //线性筛法-O(n), n = 1e7的时候基本就比埃式筛法快一倍了
// //算法核心：x仅会被其最小质因子筛去
// void get_prime(int x) {
//     for(int i = 2; i <= x; i++) {
//         if(!st[i]) prime[cnt++] = i;
//         for(int j = 0; prime[j]*i <= x ; j++) {
//             //对于任意一个合数x，假设pj为x最小质因子，当i<x/pj时，一定会被筛掉
//             st[prime[j]*i] = true;
//             if(i % prime[j] == 0) break;
//             /*
//             1.i%pj == 0, pj定为i最小质因子，pj也定为pj*i最小质因子
//             2.i%pj != 0, pj定小于i的所有质因子，所以pj也为pj*i最小质因子
//             */
//         }
//     }
// } 

void linear(int x){
    for(int i= 2;i<=x/i;i++){
        if(!st[i]) prime[cnt++] = i;
        //对于每一个合数只用最小质因子对其进行筛选
        for(int j = 0;prime[j]*i<=x;j++){
            //如果最小质因子
            st[prime[j]*i]=true;
            if(i % prime[j]==0) break;
        }
    }
}
int main() {
    int x;
    cin >> x;
    linear(x);
    cout << cnt << endl;
    return 0;
}

// 作者：竹林正在青
// 链接：https://www.acwing.com/solution/acwing/content/3776/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。