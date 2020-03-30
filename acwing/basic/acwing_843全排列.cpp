#include<iostream>
#include<vector>
using namespace std;

vector<int> nums;
vector<vector<int>> ret;

int n;

void dfs(vector<int>& nums,vector<int> &path,vector<bool> &used,vector<vector<int>>& ret){
    if(path.size()==n){
        ret.push_back(path);
        return;
    }
    for(int i = 0;i<nums.size();i++){
        if(!used[i]){
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums,path,used,ret);
            path.pop_back();
            used[i] = false;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++) nums.push_back(i);
    vector<int> path;
    vector<bool> used(n,false);
    dfs(nums,path,used,ret);
    for(int i = 0;i<ret.size();i++){
        for(int j = 0;j<ret[i].size();j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}