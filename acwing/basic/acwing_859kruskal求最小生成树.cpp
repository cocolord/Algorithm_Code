#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010, INF = 0x3f3f3f3f;

int n, m;

int p[N];

struct Edge{
    int a,b,w;
    bool operator<(const Edge & W) const{
        return w<W.w;
    }
}edges[M];
//并查集带路径压缩
int find(int x)
{
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}
// 1).记Graph中有v个顶点，e个边

// 2).新建图Graphnew，Graphnew中拥有原图中相同的v个顶点，但没有边

// 3).将原图Graph中所有e个边按权值从小到大排序

// 4).循环：从权值最小的边开始遍历每条边 直至图Graph中所有的节点都在同一个连通分量中

//                 if 这条边连接的两个节点于图Graphnew中不在同一个连通分量中

//                             添加这条边到图Graphnew中
int Kruskal()
{
    sort(edges,edges+m);
    for(int i = 1;i<=n;i++) p[i] = i;
    int res = 0,cnt = 0;
    for(int i = 0;i < m ;i++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a),b= find(b);
        if(a!=b){
            p[a] = b;
            cnt ++;
            res += w;
        }
    }
    if(cnt < n - 1)
        return INF;
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        edges[i] = {a, b, c};
    }
    
    int t = Kruskal();
    
    if (t == INF) puts("impossible");
    else cout << t << endl;
    
    return 0;
}