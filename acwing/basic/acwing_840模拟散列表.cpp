#include<iostream>
#include<string.h>
using namespace std;
const int N = 100003;
const int null = 0x3f3f3f3f;
//其实e ne是模拟链表
int e[N],h[N],ne[N];
int idx = 0;
void insert(int x){
    // 计算散列函数
    int k = (x%N + N ) % N;
    // 第idx的位置的值为x
    //插入到链表头
    e[idx] = x;
    ne[idx] = h[k];
    h[k]=idx++;
}
bool query(int x){
    int k = (x%N+N)%N;
    for(int i = h[k];i!=-1;i=ne[i])
        if(e[i]==x)
            return true;
    return false;
    
}
int main(){
    memset(h,0x3f,sizeof h);
    int n;
    cin >> n;
    while(n--){
        char op;
        cin >> op;
        int x;
        cin >> x;
        if(op=='I')
            insert(x);
        else{
            bool flag = query(x);   
            if(flag==true)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}