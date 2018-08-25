#include"stdafx.h"
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define inf 0x7ffffff
struct edge
{
	int to, cost;
};
//first 是顶点的编号，second 是最短距离
typedef pair<int, int> P;
vector<edge>  G[1010];//边表 index is the beginning point
int t, n;
int d[1010];
//单源最短路径
void dijk(int s)
{
	//初始化
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d + n + 1, inf);
	d[s] = 0;
	que.push({s,0});
	//first 是顶点的编号，second 是最短距离
	while (!que.empty())
	{
		//找一条最短边
		P p = que.top();
		que.pop();
		int a = p.first;
		int b = p.second;
		if (d[a] < b) continue;
		//从起点a出发有几条边
		//松弛
		for (int i = 0; i < G[a].size(); i++)
		{
			//从a到G[a][i].to
			edge e = G[a][i];
			if (d[e.to] > d[a] + e.cost)
			{
				d[e.to] = d[a] + e.cost;
				que.push({ e.to,d[e.to] });
			}
		}
	}
}
int main()
{
	cin >> t >> n;
	while (t--)
	{
		int r, q, p;
		cin >> r >> q >> p;
		//注意这里
		//可能重复输入多组数据、
		//但是在这个数据存储结构下是OK的
		G[r].push_back({ q,p });
		G[q].push_back({ r,p });
	}
	dijk(1);
	cout << d[n] << endl;
	return 0;
}