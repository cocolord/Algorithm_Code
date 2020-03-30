#include<iostream>
using namespace std;
const int N = 100010;
int par[N];
int rel[N];
int count = 0;
int find(int q){
    if(q!=par[q]) par[q] = find(par[q]);
    return par[q];
}
int main(){
    int n,k;
    //n 个动物 
    //k 句 话
    cin >> n >> k;
    //初始化为自己
    for(int i = 0;i<n;i++)
        par[i] = i;
    //k 句话
    for(int i = 0;i<k;i++){
        int op ,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(x > n || y > n) {count ++;continue;}
        if(op==2 && x==y) {count++;continue;}
        else {
            /* code */
        
        }
        
    }
}