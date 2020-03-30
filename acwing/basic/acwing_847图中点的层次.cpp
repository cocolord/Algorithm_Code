#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N = 100100;
queue<pair<int,int>> q;
//搜索最好带标记节点
bool used[N];
int n,m;
int main(){
    vector<vector<int>> ne(N,vector<int>(1,-1));
    cin >> n >> m;
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        ne[a].push_back(b);
    } 
    q.push({1,0});
    while(!q.empty()){
        //t -> 队头
        pair<int,int> t=q.front();
        used[t.first] = true;
        q.pop();
        if(t.first==n){
            cout<<t.second<<endl;
            return 0;
        }
        for(int i = 1;i<ne[t.first].size();i++){
            int neindex = ne[t.first][i];
            //扩展 t 的所有邻接点
            if(!used[neindex]){
                q.push({neindex,t.second + 1});
            }
        }
    }
    cout<<"-1"<<endl;
    return 0;
}