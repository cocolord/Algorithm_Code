#include<iostream>

using namespace std;

const int N=1000010;
//原数组
int a[N];
//
int q[N];

int hh=0,tt=-1;

int main(){
    int n,k;
    //处理输入
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    // //寻找最小值
    // for(int i=0;i<n;i++){
    //     //当前最小值已经不再窗口里
    //     if(hh<=tt&&i-k+1>q[hh]) hh++;
    //     //hh 队头在q中的索引
    //     //tt 队尾在q中的索引
    //     while(hh<=tt&&a[i]<a[q[tt]]) tt--;
    //     q[++tt]=i;
    //     if(i>=k-1) printf("%d ",a[q[hh]]);
    // }
    //寻找最小值
    for(int i = 0;i<n;i++){
        if(hh <= tt && hh <= i - k) hh ++;
        while(hh<=tt && a[i] < a[q[tt]]) tt--;
        q[++tt] = i;
        if(i >= k - 1 ) printf("%d",a[q[hh]]);
    }
    //寻找最大值
    hh=0,tt=-1;
    for(int i=0;i<n;i++){
        if(hh<=tt&&i-k+1>q[hh]) hh++;
        while(hh<=tt&&a[i]>a[q[tt]]) tt--;
        q[++tt]=i;
        if(i>=k-1) printf("%d ",a[q[hh]]);
    }
    
    return 0;
}