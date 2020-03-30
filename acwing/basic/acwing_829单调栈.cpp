#include<iostream>

using namespace std;

const int N=100010;

int stk[N];
int tt = 0;

int main(){
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        while(tt && stk[tt]>=x) tt--;
        if(tt && stk[tt]<x) cout<<stk[tt]<<endl;
        else cout<<-1<<endl;
        stk[++tt] = x;
    }
    return 0;
}