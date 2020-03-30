#include<iostream>
#include<vector>
using namespace std;
const int N = 100010;
bool st[N];
int ans = INT32_MAX;
int n;
int dfs(vector<vector<int>>& ne,int u){
    //当前节点和当前临街节点后的连通分支大小
    int sum = 1;
    //最大的联通分支
    int res = 0;
    st[u] = true;   
    for(int i = 1;i<ne[u].size();i++){
        if(!st[ne[u][i]]){
            int s = dfs(ne,ne[u][i]);
            res = max(res,s);
            sum += s;
        }
    }
    res = max(res,n-sum);
    ans  = min(ans,res);
    return sum;
}
int main(){
    cin >> n;
    //初始化邻接表
    vector<vector<int>> ne(N,vector<int>(1,-1));
    for(int i = 0;i<n;i++){
        int a,b;
        // cin >> a >> b;
        scanf("%d%d",&a,&b);
        ne[a].push_back(b);
        ne[b].push_back(a);
    }
    dfs(ne,1);
    cout<<ans<<endl;
}