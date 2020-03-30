#include<vector>
#include<string>
#include<iostream>
using namespace std;
const int N = 100010;
int son[N][26];
int count[N];
int idx = 0;
string str;

void insert(string& s){
    int q = 0;
    for(auto c : s){
        if(son[q][c-'a']==0){
            son[q][c-'a'] = ++idx ;
        }
        q = son[q][c-'a'];
    }
    count[q] ++ ;
}
int query(string &s){
    int q= 0 ;
    for(auto c : s){
        if(son[q][c-'a']==0)
            return 0;
        q = son[q][c-'a'];
    }
    return count[q];
}
int main(){
    int n;
    cin >> n;
    while(n--){
        char op ;
        cin >> op;
        cin >> str;
        if(op=='I') insert(str);
        else if(op=='Q') cout<<query(str) <<endl;
    }
    return 0;
}