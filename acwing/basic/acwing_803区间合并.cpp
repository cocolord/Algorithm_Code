#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void merge(vector<pair<int,int>> &coor){
    vector<pair<int,int>> ans;
    //这个排序很关键
    //! pair排序 优先左端点， 再以右端点排序
    sort(coor.begin(),coor.end());
    int st = -1e9-10,ed = -1e9-10;
    for(auto item : coor){
        if(item.first>ed){
            if(st!=-1e9-10) ans.push_back({st,ed});
            st=item.first,ed= item.second;
        }
        if(item.first<=ed){
            ed= std::max(item.second,ed);
        }
    }
    if(ans.size()!=0) ans.push_back({st,ed});  //! 如果不是空的  那我们就加上一段
    coor = ans;
}

int main(){
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> coor;
    while(n--){
        int li,ri ;
        cin >>li>>ri;
        coor.push_back({li,ri});
    }
    merge(coor);
    cout<<coor.size()<<endl;
    return 0;
}