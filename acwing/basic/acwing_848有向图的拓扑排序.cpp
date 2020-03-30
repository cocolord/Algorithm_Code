#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 100100;
int n,m;
queue<int> q;
//拓扑排序,标记入度
int d[N];
vector<int> ret;
int main(){
    vector<vector<int>> ne(N,vector<int>(1,-1));
    cin >> n >> m;
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        ne[a].push_back(b);
        d[b]++;
    }
    //放入所有入度为0
    for(int i = 1;i<=n;i++) if(!d[i]) q.push(i);
    while(!q.empty()){
        //t -> 队头
        int t=q.front();
        q.pop();
        ret.push_back(t);
        //扩展 t 的所有邻接点
        for(int i = 1;i<ne[t].size();i++){
            int neindex = ne[t][i];
            //t弹出了,所以所有临街节点的入度减一
            if(--d[neindex]==0){
                q.push(neindex);
            }
        }
    }
    if(ret.size()==n){
        for(auto c : ret)
            cout<< c <<" ";
        cout<<endl;
        return 0;
    }
    cout<<"-1"<<endl;
    return 0;
}