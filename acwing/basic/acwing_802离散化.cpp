#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 300010;
typedef pair<int,int> PII;
//所有坐标
vector<int> alls;
// 插入和询问数组
vector<PII> add,query;
//n 次插入 m次询问
int n,m;
//前缀和
int a[N],s[N];

int find(int x){
    int l = 0,r=alls.size()-1;
    while(l<r){
        int mid = l + r >> 1; 
        //根据这个性质，找第一个大于等于x的位置
        if(alls[mid]<x) l = mid + 1;
        else r = mid;
    }
    //为了满足题目要求 
    //前缀和从1 到 alls.size()
    return r + 1;
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        int x,c;
        cin >> x>>c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    for(int i = 0;i<m;i++){
        int l,r ;
        cin >> l >> r;
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    //离散化，原来的坐标映射到 0 - alls.size() -1
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    //处理修改元素
    for(auto item : add){
        int x = find(item.first);
        a[x] += item.second;
    }
    //处理前缀和
    for(int i = 1;i<=alls.size();i++) s[i] = s[i-1] + a[i];
    //处理询问
    for(auto item : query){
        int l = find(item.first);
        int r = find(item.second);
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}