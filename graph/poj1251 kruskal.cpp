#include"stdafx.h"
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
#define inf 0xffffff
//n是定义结点数
//num是定义边数
int n,num;
struct edge
{
	int from, to, cost;
};
edge es[180];
int p[130];
int r[130];
bool cmp(const edge& e1, const edge& e2)
{
	return e1.cost < e2.cost;
}
int find(int x)
{
	if (x == p[x])
		return x;
	else
		return p[x] = find(p[x]);
}
void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (r[x]<r[y]) {
		p[x] = y;
	}
	else {
		p[y] = x;
		if (r[x] == r[y]) r[x]++;
	}
}
int kruskal()
{
	int ans = 0;
	//按照edge.cost从小到大排列
	sort(es, es + num, cmp);
	//init union find
	for (int i = 0; i < n; i++)
		p[i] = i, r[i] = 0;
	for (int i = 0; i < num; i++)
	{
		edge e = es[i];
		if (find(e.from) != find(e.to))
		{
			unite(e.from, e.to);
			ans += e.cost;
		}
	}
	return ans;
}
int main()
{
	while (cin >> n && n)
	{
		char a, b;
		int temp, count;
		num = 0;
		for (int i = 0; i < n-1; i++)
		{
			cin >> a >> count;
			for (int i = 0; i < count; i++)
			{
				cin >> b >> temp;
				es[num].from = (a - 'A');
				es[num].to = (b - 'A');
				es[num].cost = temp;
				num++;
			}
		}
		cout << kruskal() << endl;
	}
	return 0;
}