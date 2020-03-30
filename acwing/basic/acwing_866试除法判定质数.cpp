#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N = 100010;
int a[N];
int main(){
    cin >> n;
    for(int i = 0;i < n ; i++){
        scanf("%d",&a[i]);
    }
    for(int j = 0;j<n;j++){
        bool is_prime = true;
        if(a[j]<2) {cout <<"No"<<endl;continue;}
        for(int i = 2;i*i<=a[j];i++){
            if (a[j] % i == 0){
                is_prime = false;
                break;
            }
        }
        if(is_prime) cout <<"Yes"<<endl;
        else cout <<"No"<<endl;
    }
    return 0;
}