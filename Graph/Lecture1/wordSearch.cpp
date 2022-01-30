#include<bits/stdc++.h>
using namespace std;
int dirx[4]={-1,1,0,0};
int diry[4]={0,0,-1,1};
bool exist(vector<vector<char>>& board, string word) {
int n=board.size();
int m=board[0].size();
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(board[i][j]==word[0]){
          if(dfs(board,word,0,i,j,n,m)){
              return true;
          }
        }
    }
}
   return false;
}
bool dfs(std::vector<std::vector<char>>& board,std::string word,int i,int row,int col,int n,int m){
        if(i>word.size()){
return false;
    }
if(i==word.size()){
    return true;
 }
    if(row>=n or col>=m or row<0 or col<0){
        return false;
    }
    if(board[row][col]!=word[i]){
        return false;
    }
    bool retval=false;
    board[row][col]='$';
    for(int d=0;d<4;d++){
        retval=dfs(board,word,i+1,row+dirx[d],col+diry[d],n,m);
        if(retval){
           break;
        }
    }
     board[row][col]=word[i];
     return retval;
}
int main(int argc, char const *argv[])
{
return 0;
}