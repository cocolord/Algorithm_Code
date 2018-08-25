#include"stdafx.h"
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
#define inf 0xffffff


int	cost[30][30];
int n;
//与一个结点相邻的最短边的权值
int mincost[30];
//判断生成树集合or顶点集合
bool used[30];

int prim()
{
	int ret = 0;
	fill(used, used + 30, false);
	fill(mincost, mincost + 30, inf);
	//让'A'做顶点
	mincost[0] = 0;
	while (true)
	{
		int v = -1;
		//注意这个 n 
		for (int i = 0; i <= n; i++)
		{
			if (!used[i] && (v == -1 || mincost[v] > mincost[i]))
			{
				v = i;
			}
		}
		if (v == -1) break;
		used[v] = true;
		ret += mincost[v];
		for (int i = 0; i <= n; i++)
		{
			mincost[i] = min(mincost[i], cost[i][v]);
		}
	}
	return ret;
}
int main()
{
	while (cin >> n && n)
	{
		char a[2], b[2];
		int temp, count;
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				if (i != j)
					cost[i][j] = cost[j][i] = inf;
				if (i == j)
					cost[i][j] = 0;
			}
		}
		n -= 1;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> count;
			while (count--)
			{
				cin >> b >> temp;
				cost[a[0] - 'A'][b[0] - 'A'] = cost[b[0] - 'A'][a[0] - 'A'] = temp;
			}
		}
		cout << prim() << endl;
	}
	return 0;
}