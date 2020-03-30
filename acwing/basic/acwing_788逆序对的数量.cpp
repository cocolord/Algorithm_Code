#include<iostream>
using namespace std;
const int N = 1e6 + 10;

int a[N];
int aux[N];
long long  count = 0;
void merge(int a[],int l,int mid, int r){
    int i = l,j = mid + 1;
    int k = 0;
    while(i<=mid && j <= r){
        // aux[k++] = a[i]<a[j]?a[i++]:a[j++];
        if (a[i]<=a[j])
            aux[k++] = a[i++];
        else {
            aux[k++] = a[j++];
            count += (mid - i + 1);
        }
    }
    while(i<=mid)
        aux[k++] = a[i++];
    while(j<=r)
        aux[k++] = a[j++];
    k = 0;
    for(int i = l,j=0;i<=r;i++,j++)
        a[i] = aux[j];
}
void mergesort(int a[],int l,int r){
    if(l>=r) return ;
    int mid = (l+r)/2; 
    mergesort(a,l,mid);
    mergesort(a,mid+1,r);
    merge(a,l,mid,r);
}

int main(){
    int n;
    cin >> n;
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    printf("%lld\n",count);
    return 0;
}