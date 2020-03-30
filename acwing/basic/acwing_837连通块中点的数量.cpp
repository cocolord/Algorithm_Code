#include<iostream>
using namespace std;
const int N = 100010;
int par[N];
int cnt[N];
//找到a的祖先 
//find and union
int find(int a){
    if(par[a]!=a) par[a] = find(par[a]);
    return par[a];
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++) par[i] = i,cnt[i]=1;
    while (m--)
    {
        string op;
        cin >> op;
        if(op=="Q1"){
            int a,b;
            cin >> a >> b;
            if(find(a)==find(b))
                cout<<"Yes"<<endl;
            else 
                cout<<"No"<<endl;
        }
        else if(op=="C"){
            int a,b;
            cin >> a >> b;
            if(find(a)==find(b)) continue;
            cnt[find(b)] += cnt[find(a)];
            par[find(a)] = find(b);
        }
        else if (op=="Q2"){
            int a;
            cin >> a;
            cout<<cnt[find(a)]<<endl;
        }
    }
    return 0;
}