#include<iostream>
#include<vector>
using namespace std;
vector<int> stk;
int idx = 0;
void push(int x){
    stk.push_back(x);

}
void pop(){
    stk.pop_back();
    // stk[idx--] = -1;
    // idx --;
}
int query(){
    return stk[stk.size()-1];
}
string empty(){
    return stk.size()==0?"YES":"NO";
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