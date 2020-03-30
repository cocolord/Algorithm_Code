#include<iostream>
#include<vector>
using namespace std;
vector<int> A,B;
vector<int> add(vector<int> & A,vector<int>& B){
    vector<int> ret;
    int t = 0;
    for(int i = 0;i<A.size()||i<B.size();i++){
        if(i<A.size())
            t+= A[i];
        if(i<B.size())
            t+=B[i];
        ret.push_back(t%10);
        t/=10;
    }
    if(t)
        ret.push_back(t);
    return ret;
}
int main(){
    string a,b;
    cin>>a>>b;
    for(int i = a.size();i>=0;i--) A.push_back(a[i]-'0');
    for(int i = b.size();i>=0;i--) B.push_back(b[i]-'0');
    vector<int> C = add(A,B);
    for(int i = 0;i<C.size();i++)
        cout<<C[i]<<" ";
    cout<<endl;
}