#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100010;

int h[N], e[N], ne[N], w[N], idx;
int dist[N];
int cnt[N];
bool st[N];

int n, m;

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++ ;
}

int spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    queue<int> q;
    for(int i = 1;i<=n;i++){
        st[i] = true;
        q.push(i);
    }
    st[1]=  true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        st[u] = false;
        for(int i = h[u];i!=-1;i=ne[i]){
            int j = e[i];
            if(dist[j] > dist[u] + w[i]){
                dist[j] = dist[u] + w[i];
                cnt[j] = cnt[u] + 1;
                if(cnt[j]>=n) return true;
                if(!st[j]){
                    q.push(j);
                    st[j]  = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        add(a, b, c);
    }
    
    if(spfa()) cout <<"Yes"<<endl;
    else
    {
            cout<<"No"<<endl;
    }
    
    
    return 0;
}