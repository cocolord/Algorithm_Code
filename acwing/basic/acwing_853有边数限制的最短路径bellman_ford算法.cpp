#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 10010;

struct Edge
{
    int a, b, c;
}edge[M];

int dist[N];
int backup[N];

int n, m, k;

void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for (int i = 0; i < k; i ++ )
    {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j ++ )
        {
            Edge e = edge[j];
            dist[e.b] = min(dist[e.b], backup[e.a] + e.c);
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
    }
    
    bellman_ford();
    
    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
    else cout << dist[n] << endl;
    
    return 0;
}