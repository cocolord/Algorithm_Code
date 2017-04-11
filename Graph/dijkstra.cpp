#include<iostream>
#include<algorithm>
#include<string.h>
#define inf 0x3f3f3f3f
#define maxn 1010
using namespace std;
bool visit[maxn];
int dist[maxn];//源点到顶点i的距离
int mp[maxn][maxn];
static int n, m;

/* 通过dist数组得出得出当下到源点的最小顶点 */
int getMin()
{
	int min = inf;
	int minIndex = 0;
	//每组数据第一行包含两个正整数N和M(0<N<200,0<M<1000)，分别代表现有城镇的数目和已修建的道路的数目
	for (int i = 0; i<n; i++)
	{
		if (!visit[i] && dist[i]<min)
		{
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}
int dijkstra(int src, int end)
{
	if(src==end)
		return 0;

	//init
	for (int j = 0; j<n; j++)
	{
		if (mp[src][j] == 0)
			dist[j] = inf;
		else
			dist[j] = mp[src][j];
	}

	dist[src] = 0;
	visit[src] = true;
	
	//松弛操作
	for (int i = 0; i < n; i++)
	{
		int u = getMin();
		visit[u] = true;
		for (int j = 0; j < n; j++)
		{
			if (!visit[j] && mp[u][j] != 0 && dist[u] != inf && mp[u][j] + dist[u] < dist[j])
			{
				dist[j] = dist[u] + mp[u][j];
			}
		}
	}
	return dist[end] == inf ? -1 : dist[end];
}
//void print()
//{
//	cout << "顶点" << "       " << "源点到顶点i的距离" << endl;
//	for (int i = 0; i<n; i++)
//	{
//		cout << i << "          " << dist[i] << endl;
//	}
//}
int main()
{
	while ((cin >> n >> m)) {
		int x, y, z;
		int start, end;
		memset(mp, 0, sizeof(mp));
		memset(visit, false, sizeof(visit));
		memset(dist, 0, sizeof(dist));
		for (int i = 0; i<m; i++)
		{
			cin >> x >> y >> z;
			if((!mp[y][x]) || mp[x][y]>z)
				mp[x][y]=mp[y][x] = z;
		}
		cin >> start >> end;
		int res = dijkstra(start, end);
		cout << res << endl;
		//print();
	}
	return 0;
}
