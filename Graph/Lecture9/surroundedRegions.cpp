#include<bits/stdc++.h>
class Solution {
public:
void solve(std::vector<std::vector<char>>& board) {
    int n=board.size();
    int m=board[0].size();
   std::vector<std::vector<bool>>vis(n,std::vector<bool>(m,false));
    std::queue<std::pair<int,int>> qu;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
             if((i==0 or i==n-1 or j==0 or j==m-1) and  board[i][j]=='O'){
                 vis[i][j]=true;
                qu.push({i,j});
            }
        }
    }
int dirx[]={0,0,-1,1};
int diry[]={-1,1,0,0};
    while(not qu.empty()){
        auto top=qu.front();
        int x=top.first;
        int y=top.second;
        qu.pop();
        for(int i=0;i<4;i++){
            int nx=x+dirx[i];
            int ny=y+diry[i];
            if(nx<n and ny < m and nx>=0 and ny >=0 and board[nx][ny]=='O' and  (not vis[nx][ny])){
               vis[nx][ny]=true;
                qu.push({nx,ny});
            }   
            }
    }
     for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                   if(!vis[i][j] and board[i][j]=='O'){
                       board[i][j]='X';
     }
     }
    }
}
};
void dfs(int i,int j,int n,int m, std::vector<std::vector<bool>>&vis){
    if(i<0 or j<0 or i>=n or j>=m or (vis[i][j]=='1')){
        return;
    }
    vis[i][j]=true;
    dfs(i,j+1,n,m,vis);
    dfs(j+1,j,n,m,vis);
    dfs(i-1,j,n,m,vis);
    dfs(i,j-1,n,m,vis);
}
    std::vector<std::vector<bool>>vis;
   void dfs(int i,int j,int n,int m,std::vector<std::vector<char>>& board){
    if(i<0||i>=n||j<0||j>=m||board[i][j]=='X'||vis[i][j]){
        return;
    }
    vis[i][j]=true;
    dfs(i-1,j,n,m,board);
    dfs(i+1,j,n,m,board);
    dfs(i,j-1,n,m,board);
    dfs(i,j+1,n,m,board);
    return;
}
void solve(std::vector<std::vector<char>>& board){
    int n=board.size();
    int m=board[0].size();
    vis.resize(n,std::vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0 or j==0 or i==n-1 or j==m-1) and (board[i][j]=='O')){
                dfs(i,j,n,m,board);
            }
        }
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='O' and (! vis[i][j])){
                board[i][j]='X';
            }
        }
    }
}
int main(int argc, char const *argv[])
{
return 0;
}