#include<iostream>
#include<vector>
using namespace std;
vector<int> A;
vector<int> mul(vector<int> &A,int b){
    int t = 0;
    vector<int> ret;
    for(int i = 0;i<A.size();i++){
        t = t + A[i] * b;
        ret.push_back(t%10);
        t = t / 10;
    }
    if(t>0) ret.push_back(t);
    while(A.size()>=1 && A.back()==0) A.pop_back();
    return ret;
}
int main()
{
    string a;
    int b;
    cin >> a >> b;
    for(int i = a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    auto C = mul(A,b); 
    for(int i = C.size()-1;i>=0;i--) cout<<C[i];
    return 0;
}