#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 510,M=100010;
int n,m;
int g[N][N];
int dist[N];
bool st[N];
int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    //n 个节点需要n次更新
    for(int i = 0;i < n ; i++){
        int t = -1;
        //贪心每次找出最小节点
        for(int j = 1;j<=n;j++){
            if(!st[j] && (t==-1 || dist[t]>dist[j]))
                t = j;
        }
        //访问过就不再访问
        st[t] = true;
        for(int j = 1;j<=n;j++){
            dist[j] = min(dist[j],dist[t] + g[t][j]);
        }
    }
    return dist[n]==0x3f3f3f3f?-1:dist[n];
}
int main(){
    cin >> n >> m;
    memset(g,0x3f,sizeof g);
    while(m--){
        int a,b,c;
        cin >> a  >> b >> c;
        g[a][b] = min(g[a][b],c);
    }
    cout<<dijkstra()<<endl;
}