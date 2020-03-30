#include<iostream>
#include<vector>
#include<string>
using namespace std;


vector<int> prefix_function(string& s){
    //定义前缀函数
    //如果当前这一位失配,回到哪一位继续匹配?
    //SSS77SSS77 
    // 0 1 2 0 0 1 2 3 4 5 
    vector<int> pre(s.size(),0);
    //从模式串的第1索引位开始
    //计算前缀函数
    for(int i = 1,j = 0;i<s.size();i++) {
        //j 是 前一位的前缀函数
        j = pre[i-1];
        while(j > 0 && s[i]!=s[j]) j = pre[j-1];
        if(s[i]==s[j]) j ++;
        pre[i] = j;
    }
    return pre;
}

int main(){
    string p,s;
    int m,n;
    //模板串
    cin >> n;
    cin >> p;

    //模式串
    cin >> m;
    cin >> s;
    // 计算模板串的前缀函数
    vector<int> pre = prefix_function(p);

    for(int i = 0,j = 0;i<m;i++){
        while(j>0 && p[j]!=s[i]) j=pre[j-1];
        if(p[j] == s[i]) j++;
        if(j==n) {
            cout << i - j + 1<<" ";
            //匹配成功后,这一位也可以不匹配,那就回到前一位的前缀位置
            j = pre[j-1];
        }
    }
    return 0;
}