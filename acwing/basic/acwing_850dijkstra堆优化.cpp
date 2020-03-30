#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5+10;

int n, m;
//临街表
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b,w[idx]=c,ne[idx] = h[a],h[a]=idx++;
}

int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    priority_queue<PII,vector<PII>,std::greater<PII>> heap;
    heap.push({0,1});
    //loop n times
    while(!heap.empty()){
        //O(n) 查找最小的
        PII t = heap.top();
        heap.pop();
        int ver = t.second,distance = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        //O(mlogn) 更新m条边
        for(int i = h[ver];i!=-1;i=ne[i]){
            int j = e[i];// j 是 i 的临接边
            if(dist[j] > distance + w[i]){
                dist[j] = distance + w[i];
                heap.push({dist[j],j});
            }
        }
    }
    return dist[n]==0x3f3f3f3f?-1:dist[n];
}
int main()
{
    scanf("%d%d", &n, &m);
    
    memset(h, -1, sizeof h);
    while(m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    
    cout << dijkstra() << endl; 
    
    return 0;
}