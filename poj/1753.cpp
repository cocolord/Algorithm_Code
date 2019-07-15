#include<iostream>
#include<cstdio>
#define inf 0xffffff
using namespace std;

int ret = 0xffffff;
bool mat[10][10] = {false};
//b 1
//w 0
bool check(){
    int result = 0;
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            result += mat[i][j];
        }
    }
    // for(int i = 0;i<4;i++){
    //     for(int j = 0;j<4;j++){
    //         cout<<mat[i][j];
    //     }
    //     cout<<endl;
    // }
    if(result==0||result==16) return true;
    return false;
}
void flip(int i,int j)
{
    mat[i][j] = !mat[i][j];
    if(i-1>=0) mat[i-1][j] = !mat[i-1][j];
    if(i+1<=3) mat[i+1][j] = !mat[i+1][j];
    if(j-1>=0) mat[i][j-1] = !mat[i][j-1];
    if(j+1<=3) mat[i][j+1] = !mat[i][j+1];
}

void dfs(int i,int j,int count)
{
    //保存一个最小结果
    if(check())
    {
        if(count<ret)
            ret=count;
        return;
    }
    if(i>=4 || j>=4) return;
    //对于当前步 只有翻与不翻

    int ni = (i+1)%4;
    int nj = j + (i+1)/4;
    //这一步不反转
    dfs(ni,nj,count);
    //这一步翻转
    flip(i,j);
    dfs(ni,nj,count+1);
    //翻转回来
    flip(i,j);
    return;

}
int main()
{
    char c[10];
    for(int i = 0;i<4;i++){
        scanf("%s",c);
        for(int j = 0;j<4;j++){
            if(c[j] == 'b') mat[i][j]=1;
            else if(c[j] =='w') mat[i][j]=0;
        }
    }
    dfs(0,0,0);
    if(ret>=inf) cout<<"Impossible\n";
    else
    {
        cout<<ret<<endl;
    }
}