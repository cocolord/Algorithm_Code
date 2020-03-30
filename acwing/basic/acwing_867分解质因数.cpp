#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N = 100010;
int a[N];
void divide(int x){
    for(int i = 2;i*i<=x;i++){
        if(x % i == 0){
            int cnt = 0;
            while ( x % i == 0){
                x/=i;
                cnt ++;
            }
            cout<<i<<" "<<cnt<<endl;
        }
    }
    if(x!=1) cout << x <<" " << "1"<<endl; 
}
int main(){
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        divide(x);
        puts("");
    }
    return 0;
}