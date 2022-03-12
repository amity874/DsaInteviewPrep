class Solution {
public:
int bfs(vector<vector<int>>& grid){
	int n=grid.size();
	int m=grid[0].size();
    std::queue<std::pair<int,int>>qu;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(grid[i][j]==1){
    			qu.push({i,j});
    		}
    	}
    }
    if(qu.size()==0 or qu.size()==n*m){
        return -1;
    }
    qu.push({-1,-1});
    int xdir[4]={-1,1,0,0};
    int ydir[4]={0,0,-1,1};
    int count=0;
    while(not qu.empty()){
    	auto tp=qu.front();
    	qu.pop();
    	if(tp.first==-1 && tp.second==-1 && qu.size()>0){
    		count++;
    		qu.push({-1,-1});
    	}
    	for(int dir=0;dir<4;dir++){
    		int x=tp.first+xdir[dir];
    		int y=tp.second+ydir[dir];
    		if(x<0 or y<0 or x>=n or y>=m or grid[x][y]==1){
    			continue;
    		}
    		qu.push({x,y});
    		grid[x][y]=1;
    	}
    }
    return count--;
}
int maxDistance(vector<vector<int>>& grid) { 
return bfs(grid);       
}
};