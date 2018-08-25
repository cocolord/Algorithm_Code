#include"stdafx.h"
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define inf 0x7ffffff
int num = 1;
int t, n;
int cost[1010][1010];
int d[1010];
bool used[1010];
//单源最短路径
void dijk(int s)
{
	fill(d, d + n + 1, inf);
	fill(used, used + n + 1, false);
	d[s] = 0;
	while(true)
	{
		int v = -1;
		//从未使用的顶点中选一个最小
		for (int j = 1; j <= n; j++)
		{
			if (!used[j] && (v == -1 || d[j] < d[v])) v = j;
		}
		if (v == -1) break;
		used[v] = true;
		//松弛
		for (int i = 1; i <= n; i++)
			d[i] = min(d[i], cost[v][i] + d[v]);
	}
}
int main()
{
	cin >> t >> n;
	for (int i = 1; i <= 1010; i++)
		for (int j = 1; j <= 1010; j++)
			cost[i][j] = inf;
	while (t--)
	{
		int r, q, p;
		cin >> r >> q >> p;
		//注意这里
		//可能重复输入多组数据
		if(p<cost[r][q])
			cost[r][q] = cost[q][r] = p;
	}
	dijk(1);
	cout << d[n] << endl;
	return 0;
}