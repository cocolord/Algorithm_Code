#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N = 110;
//队列
queue<pair<int,int>> q;
//走到{i,j}所用的步数
int step[N][N];
//棋盘格
int board[N][N];
int n,m;
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
int main(){
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            scanf("%d",&board[i][j]);
            step[i][j] = -1;
        }
    }
    q.push({1,1});
    step[1][1]= 0;
    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop();
        int x = temp.first,y = temp.second;
        for(int i= 0;i<4;i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            //如果当前位置可以走就放入队列中
            //如果当前访问过就不再更新? 因为如果考虑四个方向,那确实不应该重复访问同一个位置
            if(newx >=1 && newx <=n && newy >= 1 && newy <= m && board[newx][newy]==0 &&step[newx][newy]==-1 ){
                step[newx][newy] = step[x][y] + 1;//std::min(step[newx][newy],step[x][y]+1);
                q.push({newx,newy});
            }
        }
    }
    cout<<step[n][m];
    return 0;
}