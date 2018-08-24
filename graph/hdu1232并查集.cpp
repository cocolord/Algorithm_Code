#include"stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;

int par[2018];
int n, m;
int find(int x)
{
	if(x!=par[x])
		par[x] = find(par[x]);
	return par[x];
}
void merge(int x, int y)
{
	int tempx = find(x), tempy = find(y);
	if (tempx == tempy)
		return;
	//将x的根节点指向y
	else
		par[tempx] = tempy;
}
int main()
{
	while (scanf("%d",&n) && n)
	{
		scanf("%d", &m);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			par[i] = i;

		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			merge(x, y);
		}
		//只需确定连通分支的数量
		for (int i = 1; i <= n; i++)
		{
			//判断根节点数量
			if (par[i]==i)
			{
				ans++;
			}
		}
		std::cout << ans - 1 << endl;
	}
	return 0;
}