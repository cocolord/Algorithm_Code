#include<iostream>
using namespace std;
int a[100010];
int k_th(int l,int r,int k){
    if(l==r) return a[l];
    // partition
    int i = l-1,j = r + 1,pivot = a[(l+r)/2];
    while (i<j)
    {
        /* code */
        while(a[++i]<pivot);
        while(a[--j]>pivot);
        if(i<j)
            swap(a[i],a[j]);
    }
    int s1 = j - l + 1;
    if(k<=s1) 
        return k_th(l,j,k);
    else   
        return k_th(j+1,r,k-s1);
    
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    cout<< k_th(0,n-1,k) << endl;
    return 0;
}