#include<iostream>
#include<cstring>
using namespace std;
typedef unsigned long long ULL;
//字符串哈希防止冲突的方法

const int N = 100010, P = 131;
ULL p[N],h[N];
char str[N];
//
ULL get (int l1,int r1){
    return h[r1] - h[l1-1]*p[r1-l1+1];
}

int main(){
    int n,m;
    scanf("%d%d%s",&n,&m,str+1);
    p[0] =1;
    for(int i = 1;i<=n;i++){
        p[i] = p[i-1]*P;
        h[i] = h[i-1]*P + str[i];
    }
    while(m--){
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(get(l1,r1)==get(l2,r2))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}