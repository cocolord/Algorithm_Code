#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;
int n,m,mp[maxn][maxn], dist[maxn], vis[maxn];
int prime(int start){
    memset(vis, 0, sizeof(vis));
    memset(dist, INF, sizeof(dist)); 
    vis[start] = 1;
    int pt, mindist, path = 0, cur = start;
    for(int i=2; i<=n; ++i)
    {
        mindist = INF;
        pt = -1;
        for(int i=1; i<=n; ++i)
        {
            if(!vis[i] && mp[cur][i] > 0 && mp[cur][i] < dist[i])
            {
                dist[i] = mp[cur][i];
            }
            if(!vis[i] && mindist > dist[i])
            {
                mindist = dist[i];
                pt = i;
            }
        }
        path += mindist;
        vis[pt] = 1;
        cur = pt;
    }
    return path;
}
// 9 14
// 1 2 4
// 2 3 8
// 3 4 7
// 4 5 9
// 5 6 10
// 6 7 2
// 7 8 1
// 8 9 7
// 2 8 11
// 3 9 2
// 7 9 6
// 3 6 4
// 4 6 14
// 1 8 8
int main(){ 
    int x, y, val, ans;
    while(scanf("%d %d", &n, &m) != EOF){
        memset(mp, 0, sizeof(mp));
        for(int i=0; i<m; ++i){
            scanf("%d %d %d", &x, &y, &val);
            mp[x][y] = mp[y][x] = val;
        }
        ans = prime(1);
        printf("%d\n", ans );
    }
    return 0; 
}