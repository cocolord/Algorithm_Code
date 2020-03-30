#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;

const int N = 100010, M = 200010;

int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
//染色分为染成1 和 2
bool dfs(int u,int c){
    color[u] = c;
    for(int i = h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(!color[j]){
            if(!dfs(j,3-c)) return false;
        }
        else if (color[j]==c) return false;
    }
    return true;
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    
    bool flag = true;
    //对于n个点
    for (int i = 1; i <= n; i ++ )
    {
        //如果没有染色过
        if (!color[i])
        {
            //进行染色
            //false染色出现矛盾
            if (!dfs(i, 1))
            {
                flag = false;
                break;
            }
        }
    }
    
    if (flag) puts("Yes");
    else puts("No");
    
    return 0;
}