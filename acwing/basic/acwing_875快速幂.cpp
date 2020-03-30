#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL ;

LL power(LL a,LL b,LL p){
    LL ret = 1;
    while(b){
        if(b & 1)
            ret = ret * a % p;
        b = b >> 1;
        a = a * (LL)a % p;
    }
    return ret;
}
int  main(){
    LL n;
    scanf("%lld", &n);
    while(n--){
        LL a,b,p;
        scanf("%lld%lld%lld",&a,&b,&p);
        cout << power(a,b,p) << endl;
    }
    return 0;
}