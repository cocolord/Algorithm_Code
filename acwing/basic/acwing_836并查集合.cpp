#include<iostream>
using namespace std;
const int N = 100010;
int a[N];
int par[N];
//找到a的祖先 
//find and union
int find(int a){
    if(par[a]!=a) par[a] = find(par[a]);
    return par[a];
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++) a[i] = i,par[i]=i;
    while (m--)
    {
        char op;
        cin >> op;
        int a,b;
        cin >> a >> b;
        if(op=='Q'){
            if(find(a)==find(b))
                cout<<"Yes"<<endl;
            else 
                cout<<"No"<<endl;
        }
        else {
            par[find(a)] = find(b);
        }
    }
    return 0;
}