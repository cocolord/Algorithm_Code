#include<iostream>
using namespace std;
int a[100010];
// int partition(int a[],int l,int r){
//     int pivot = a[(l+r)/2];
//     int i  = l -1 ,j = r + 1;
//     while(i<j){
//         do i++;while(a[i]<pivot);
//         do j--;while(a[j]>pivot);
//         if(i<j){
//             int temp = a[i];
//             a[i] = a[j];
//             a[j] = temp;
//         }
//     }
//     return j;
// }

int partition(int a[],int left,int right) {
    int pivot  = left;
    int index = pivot + 1;
    for(int i = index;i<=right;i++){
        if(a[i]<a[pivot]){
            swap(a[i],a[index]);
            index ++;
        }
    }
    index -= 1;
    swap(a[index],a[pivot]);
    return index;
}

int k_th(int a[],int l,int r,int k){
    // k -= 1;
    int index ;
    while (l<r){
        index = partition(a,l,r);
        // cout<<index<<endl;
        if(index==k)
            break;
        else if (index > k){
            r = index - 1;
        }
        else if (index < k ){
            l = index + 1;
        }
    }
    return a[k];
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    cout<< k_th(a,0,n,k) << endl;
    return 0;
}