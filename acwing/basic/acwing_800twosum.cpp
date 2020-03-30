#include<iostream>
using namespace std;
int a[100010];
int b[100010];
int main(){
    int n,m,x;
    cin>>n>>m>>x;
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i = 0;i<m;i++) cin>>b[i];
    //     4 5 6
    // 1 2 4 7
    // 3 4 6 8 9
    int i = 0, j = m-1;
    for(;i<n;i++){
        //满足某个性质
        while(j>=0 && a[i]+b[j]>x) j --;
        if(a[i]+b[j]==x){
            cout<<i<<" " <<j<<endl;
            return 0;
        }
    }   
}