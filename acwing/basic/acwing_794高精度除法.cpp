#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> A;
vector<int> div(vector<int> &A,int& b,int &r){
    vector<int> ret;
    r =0;
    for(int i = A.size()-1;i>=0;i--){
        r = r * 10 + A[i];
        ret.push_back(r/b);
        r %=b;
    }
    reverse(ret.begin(),ret.end());
    while(ret.size()>1 && ret.back()==0) ret.pop_back();
    return ret;
}
int main()
{
    string a;
    int b;
    cin >> a >> b;
    for(int i = a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    int r ;
    auto C = div(A,b,r); 
    for(int i = C.size()-1;i>=0;i--) cout<<C[i];
    cout<<endl<<r<<endl;
    return 0;
}