#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 100010;

int h[N], ne[M], e[M], idx;
bool st[N];
int match[N];

int n1, n2, m;

bool find(int x){
    for(int i = h[x];i!=-1;i=ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = true;
            //右边没有匹配到左边 或者右边匹配到的左边可以换一个右边
            if(match[j]==0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
void add(int a, int b)
{
    // e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
    e[idx]=  b,ne[idx]=h[a],h[a]=idx++;
}

int main()
{
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);
    
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        
        add(a, b);
    }
    int res  =0;
    for(int i  = 1;i<=n1;i++){
        memset(st,false,sizeof st);
        if(find(i)) res ++;
    }
    cout << res << endl;
    
    return 0;
}