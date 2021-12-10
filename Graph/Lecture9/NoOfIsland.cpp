#include<bits/stdc++.h>
#define ll long long int
void dfsHelper(std::vector<std::vector<char>>& grid,int i,int j){
    int n=grid.size();
    int m=grid[0].size();
    if(i>=m ||j>=m || i<0 || j<0){
        return;
    }
    if(grid[i][j]=='0')return ;
    grid[i][j]='0';
    dfsHelper(grid,i+1,j);
    dfsHelper(grid,i,j+1);
    dfsHelper(grid,i-1,j);
    dfsHelper(grid,i,j-1);
}
int numIslands(std::vector<std::vector<char>>& grid) { 
    int n=grid.size();
    int m=grid[0].size();
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                cnt++;
                dfsHelper(grid,i,j);
            }
        }
    }       
}
int main(int argc, char const *argv[])
{
return 0;
}