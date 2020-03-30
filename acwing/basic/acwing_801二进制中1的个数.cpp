#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int x ;
        scanf("%d",&x);
        int count = 0;
        while(x!=0){
            if(x&1==1)
                count++;
            x >>= 1;
        }
        printf("%d",count);
    }
    return 0;
}