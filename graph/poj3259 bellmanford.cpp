/********************************************************************
AZmaple	3259	Accepted	228K	1563MS
题意：农夫 FJ 有 N 块田地【编号 1...n】 (1<=N<=500)
田地间有 M 条路径 【双向】(1<= M <= 2500)
同时有 W 个孔洞,可以回到以前的一个时间点【单向】(1<= W <=200)
问：FJ 是否能在田地中遇到以前的自己
算法：bellman_ford 判断是否有负环
思路：田地间的双向路径加边,权值为正
孔洞间的单向路径加边,权值为负【可以回到以前】
判断有向图是否存在负环
因为如果存在了负数环,时间就会不停的减少,
那么 FJ 就可以回到以前更远的地方,肯定能遇到以前的自己的
*******************************************************************/

#include"stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
#define inf 100100
//Each of FJ's farms comprises N (1 ≤ N ≤ 500) fields conveniently numbered 1..N, M (1 ≤ M ≤ 2500) paths,
//and W (1 ≤ W ≤ 200) wormholes.
int n, m, w ,f;
int num;
struct edge
{
	int from, to, cost;
};

edge es[5500];int d[510];
//求解从起点出发到所有点的最短距离
//并判断负圈
bool bf(int s)
{
	
	//单源最短路径维护的距离数组
	//for (int i = 1; i <= n; i++) d[i] = inf;
	memset(d, 0x3f,sizeof(d));
	d[s] = 0;
	for (int j = 1; j < n; j++)
	{
		bool update = false;
		for (int i = 1; i < num; i++)
		{
			edge e = es[i];
			if (d[e.from] != inf && d[e.to] > d[e.from] + e.cost)
			{
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		//寻找满足题目条件的负圈
		if (d[s] < 0)
			return 1;
		if (!update)
			return 0;
	}
	return 0;
}
int main()
{
	cin >> f;
	while (f--)
	{
		cin >> n >> m >> w;
		int s, e, t;
		num = 1; 
		for (int i = 0; i < m; i++)
		{
			cin >> s >> e >> t;
			es[num].from = s;
			es[num].to = e;
			es[num].cost = t;
			num++;
			es[num].from = e;
			es[num].to = s;
			es[num].cost = t;
			num++;
		}
		for (int i = 0; i < w; i++)
		{
			cin >> s >> e >> t;
			es[num].from = s;
			es[num].to = e;
			es[num].cost = (-1)*t;
			num++;
		}
		bool flag = false;
		for (int i = 1; i < num; i++)
		{
			if (bf(i))
			{
				flag = true;
				break;
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
