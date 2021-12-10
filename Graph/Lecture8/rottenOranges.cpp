#include<bits/stdc++.h>
int orangesRotting(std::vector<std::vector<int>>& grid) {       
    int n=grid.size();
    int m=grid[0].size();
    std::queue<std::pair<int,int>> qu;
    int total=0;
    int t=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!=0){
                total++;
            }
            if(grid[i][j]==2){
                qu.push({i,j});
            }
        }
    }
    int dirx[]={0,0,-1,1};
    int diry[]={-1,1,0,0};
    while(not qu.empty()){
        int k=qu.size();
        cnt+=k;
        while(k--){//this is for each level
        int x=qu.front().first;
        int y=qu.front().second;
        qu.pop();
        for(int i=0;i<4;i++){
            int nx=x+dirx[i];
            int ny=y+diry[i];
            if(nx>= n or ny>=m or nx<0 or ny<0 or grid[nx][ny]!=1)continue;
            qu.push({nx,ny});
        }
        }
        if(not qu.empty()){
            t++;
        }
    }
    return total==cnt?t:-1;
}
int main(int argc, char const *argv[])
{
return 0;
}