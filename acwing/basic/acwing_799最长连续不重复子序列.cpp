#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int a[100010];
int main(){
    int n;
    cin>>n;
    //统计i j 之间元素出现的次数
    unordered_map<int,int> hash;
    // cin>>a;
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    int res = 0;
    for(int i = 0,j = 0;i<n;i++){
        hash[a[i]]++;
        while(j <= i && hash[a[i]]>1){
            hash[a[j]]--;
            j++;
        }
        res = max(res,i - j + 1);
    }
    cout<<res<<endl;

    return 0;
}