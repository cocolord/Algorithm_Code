#include<iostream>
#include<vector>
using namespace std;

vector<vector<char>> board;
int result =0;
int n;
//当前位置是否可以放一个皇后
bool check(vector<vector<char>>& board,int i,int j){
    //行
    for(int k =0 ;k<n;k++){
        if(board[i][k]=='Q')
            return false;
    }
    //列
    for(int k = 0;k<n;k++){
        if(board[k][j]=='Q')
            return false;
    }
    //左上
    for(int p = i,q = j;p>=0&&q>=0;p--,q--){
        if(board[p][q]=='Q')
            return false;
    }
    //右下
    for(int p = i,q = j;p<n&&q<n;p++,q++){
        if(board[p][q]=='Q')
            return false;
    }    
    //左下
    for(int p = i,q = j;p<n&&q>=0;p++,q--){
        if(board[p][q]=='Q')
            return false;
    }
    //右上
    for(int p = i,q = j;p>=0&&q<n;p--,q++){
        if(board[p][q]=='Q')
            return false;
    }
    return true;
}
void print_board(){
    for(auto c : board){
        for(auto e : c)
            cout<<e<<" ";
        cout<<endl;
    }
    // cout<<endl;
}
//按行枚举应该是要容易一些
void dfs(vector<vector<char>>& board,int i){
    if(i>=n){
        print_board();
        return ;
    }
    for(int q = 0;q < n ; q ++ ){
        if(check(board,i,q)){
            board[i][q] = 'Q';
            dfs(board,i+1);
            board[i][q]='.';
        }
    }
    
}
int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        board.push_back(vector<char>());
        for(int j = 0;j<n;j++){
            board[i].push_back('.');
        }
    }
    dfs(board,0);
    return result;
}