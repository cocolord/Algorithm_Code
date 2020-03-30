#include<iostream>
using namespace std;
const int N = 1000010;
int prime[N];
bool st[N];
int phi[N];
int cnt;
typedef long long LL;
LL get_euler(int x){
    phi[1] = 1;
    for(int i = 2;i<=x;i++){
        if(!st[i]){
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0;prime[j]<=x/i;j++){
            st[prime[j]*i]=true;
            if(i % prime[j]==0){
                phi[i*prime[j]] = prime[j] * phi[i];
                break;
            }
            //phi[prime[j]*i] = prime[j] * phi[i] * ( 1- 1/prime[j])
            phi[i*prime[j]] = phi[i] * (prime[j]-1);
        }
    }
    LL ret = 0;
    for(int i = 1;i <= x;i++)
        ret += phi[i];
    return ret;
}

int main(){
    int n;
    cin >> n;
    cout << get_euler(n) << endl;
    return 0;
}