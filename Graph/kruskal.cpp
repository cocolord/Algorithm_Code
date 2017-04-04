#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAX = 50000 * 2;
struct EDGE
{
	int a, b, w;
}edge[MAX];
int f[MAX], r[MAX];
bool cmp(int a, int b)
{
	return edge[a].w<edge[b].w;
}
int find(const int x)
{
	if (x == f[x])return x;
	return f[x] = find(f[x]);
}
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int i, j;
		for (i = 0; i<m; i++)
		{
			scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].w);
		}
		//连通分支
		for (i = 1;  i <= n; i++)   f[i] = i;
		for (j = 0; j<m; j++) r[j] = j;
		//边的权重排序
		sort(r, r + m, cmp);
		int ans = 0;
		for (i = 0; i<m; i++)
		{
			int a = find(edge[r[i]].a);
			int b = find(edge[r[i]].b);
			if (a != b)
			{
				f[a] = b;

				ans += edge[r[i]].w;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}