#include<iostream>
#include<vector>
using namespace std;
vector<int> A;
vector<int>B;
vector<int> sub(vector<int> & A,vector<int>& B){
    vector<int> ret;
    for(int i = 0,t=0;i<A.size();i++){
        t =A[i]-t;
        if(i<B.size()) t -= B[i];
        ret.push_back((t+10)%10);
        if(t<0)
            t = 1;
        else 
            t= 0;
    }
    while(ret.size()>1 && ret.back()==0) ret.pop_back();
    return ret;
}
bool cmp(vector<int> &A,vector<int> &B){
    if(A.size()!=B.size())
        return A.size()>B.size();
    else {
        for(int i = A.size()-1;i>=0;i--){
            if(A[i]>B[i])
                return true;
            else if(A[i]<B[i]) 
                return false;
        }
    }
    return true;
}

int main(){
    string a,b;
    cin>>a>>b;
    for(int i = a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    for(int i = b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
    if(cmp(A,B))
    {
        auto C = sub(A,B);
        
        for(int i=C.size()-1;i>=0;i--)
            cout<<C[i];
    }
    else
    {
        cout<<'-';
        auto C = sub(B,A);
    
        for(int i=C.size()-1;i>=0;i--)
            cout<<C[i];
    }
    // for(int i=C.size()-1;i>=0;i--)
    //     cout<<C[i];
    return 0;
}