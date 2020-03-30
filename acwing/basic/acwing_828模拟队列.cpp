#include<iostream>
#include<vector>
using namespace std;
int que[100010];
int l=0,r=0;
void push(int x){
    que[r++] = x;
}
void pop(){
    l= l + 1;
}
int query(){
    return que[l];
}
string empty(){
    return r-l==0?"YES":"NO";
}
int main(){
    int M;
    cin>>M;
    while(M--){
        string op;
        cin>>op;
        int x;
        if(op=="push"){
            cin >> x;
            push(x);
        }
        else if (op=="pop"){
            pop();
        }
        else if (op=="query"){
            cout << query() <<endl;
        }
        else if (op=="empty"){
            cout << empty()<<endl;
        }
    }
    return 0;
}