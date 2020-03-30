#include <iostream>
#include <cstring>

using namespace std;
// 1).输入：一个加权连通图，其中顶点集合为V，边集合为E；

// 2).初始化：Vnew = {x}，其中x为集合V中的任一节点（起始点），Enew = {},为空；

// 3).重复下列操作，直到Vnew = V：

// a.在集合E中选取权值最小的边<u, v>，其中u为集合Vnew中的元素，而v不在Vnew集合当中，并且v∈V（如果存在有多条满足前述条件即具有相同权值的边，则可任意选取其中之一）；

// b.将v加入集合Vnew中，将<u, v>边加入集合Enew中；

// 4).输出：使用集合Vnew和Enew来描述所得到的最小生成树。

const int N = 510, M = 100010, INF = 0x3f3f3f3f;

int g[N][N];
bool st[N];
int dist[N];

int n, m;

int prim()
{
    memset(dist,0x3f,sizeof dist);
    int ret = 0;
    for(int i = 0;i<n;i++){
        int t = -1;
        for(int j = 1;j <= n; j++){
            if(!st[j] && (t==-1 || dist[j] < dist[t]))
                t= j;
        }
        if(i && dist[t] == INF) return INF;
        if(i) ret += dist[t];
        st[t] = true;
        for(int j = 1;j<=n;j++){
            dist[j] = min(dist[j],g[j][t]);
        } 
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    int t = prim();
    
    if (t >= 0x3f3f3f3f / 2) puts("impossible");
    else cout << t << endl;
    
    return 0;
}