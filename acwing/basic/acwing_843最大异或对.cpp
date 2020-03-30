#include<vector>
#include<string>
#include<iostream>
using namespace std;
const int N=3e6;
const int M=100010;

int son[N][2];

int a[M];
int idx;

void insert(int x){
    int q = 0;
    for(int i = 31;i>=0;i--){
        int u = (x >> i) & 1;
        if(son[q][u]==0)
            son[q][u] = ++idx;
        q = son[q][u];
    }
}
int query(int x){
    int ans = 0;
    int q = 0;
    for(int i = 31;i>=0;i--) {
        int u = (x >> i) & 1;
        if(!son[q][!u]){
            q = son[q][u];
            ans *= 2;
        }
        else {
            q = son[q][!u];
            ans = ans * 2 + 1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0;i<n;i++) scanf("%d",&a[i]);
    for(int i = 0;i<n;i++)
        insert(a[i]);
    int res = -1;
    for(int i =0 ;i<n;i++){
        res = max(res,query(a[i]));
    }
    cout<< res << endl;
    return 0;
}