#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int heap[N];
int idx = 0;
void sink(int u){
    // when to sink?
    int t = u;
    if(2*u <= idx && heap[2*u]<heap[t]) t= 2*u;
    if(2*u + 1 <= idx && heap[2*u+1]<heap[t]) t = 2*u + 1;
    if(u!=t){
        // swap(h[u],h[t]);
        int temp = heap[u];
        heap[u] = heap[t];
        heap[t] = temp;
        sink(t);
    }
}
void swim(){
    // when to swim?
}
int main(){
    //最小堆
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%d",&heap[i]);
    }
    idx = n;
    for(int i = n/2;i>=0;i--)
        sink(i);
    // for(int i = 1;i<=n;i++)
    //     cout<<heap[i]<<" ";
    // puts("");
    //最后只要前ｍ个

    while(m--){
        //删除首节点
        cout<<heap[1]<<" ";
        heap[1] = heap[idx];
        idx--;
        sink(1);
    }
}