#include<iostream>
using namespace std;
int a[100086];
int partition(int a[],int left,int right){
    // if(left<right){
    int pivot = left;
    int index = pivot + 1;
    for(int i = index;i<=right;i++){
        if(a[i]<a[pivot]){
            swap(a[i],a[index]);
            index ++;
        }
    }
    index --;
    swap(a[index],a[pivot]);
    return index ;
    // }
}
void qsort(int a[],int left,int right){
    if(left<right){
        int pivot = partition(a,left,right);
        // cout<<pivot<<endl;
        qsort(a,left,pivot-1);
        qsort(a,pivot+1,right);

    }
}
int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    qsort(a,0,n-1);
    for(int i = 0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}