#include<iostream>
using namespace std;

const int N = 100010;
int b[N];
int a[N];
void insert(int b[],int l,int r,int c){
    b[l] += c;
    b[r+1] -= c;
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
        scanf("%d",&a[i]);
    //初始化差分序列
    for(int i = 1;i<=n;i++)
        insert(b,i,i,a[i]);
    //修改差分序列
    while(m--){
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        insert(b,l,r,c);    
    }
    for(int i = 1;i<=n;i++) b[i] += b[i-1];
    for(int i =1;i<=n;i++) printf("%d ",b[i]);
    return 0;
}