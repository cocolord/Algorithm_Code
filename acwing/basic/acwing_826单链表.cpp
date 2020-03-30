#include <iostream>

using namespace std;

const int N = 100010;
// 关键时两个数组
int e[N],ne[N];
//一个用于指向投节点，一个用于指向当前数组最后一个使用的节点
int head=-1, idx = 1;
int n;

void addToHead(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx ++ ;
}

void remove(int k){
    ne[k] = ne[ne[k]];
}

void insert(int k, int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++ ;
}

int main(){
    cin >> n;
    while(n -- ){
        string op;
        cin >> op;
        if(op == "H"){
            int x;
            cin >> x;
            addToHead(x);
        }else if(op == "D"){
            int k;
            cin >> k;
            if(k == 0) head = ne[head];
            else remove(k);
        }else if(op == "I"){
            int k, x;
            cin >> k >> x;
            insert(k, x);
        }
    }
    for (int i = head; i != -1; i = ne[i] ) printf("%d ", e[i]);    
    return 0;
}