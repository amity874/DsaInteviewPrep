class Solution {
public:
    struct triplt{
	int src;
	int dest;
	int cost;
};
int xdir[4]={-1,1,0,0};
int ydir[4]={0,0,-1,1};
int minCost(vector<vector<int>>& grid) {
	int n=grid.size();
	int m=grid[0].size();
	std::deque<triplt> dq;
	dq.push_front({0,0,0});
	std::set<std::pair<int,int>>visited;
    // visited.insert({0,0});
	while(not dq.empty()){
		auto curr=dq.front();
        visited.insert({curr.src,curr.dest});
		dq.pop_front();
		if(curr.src==n-1 and curr.dest==m-1){
			return curr.cost;
		}
		for(int d=0;d<4;d++){
			int x=curr.src+xdir[d];
			int y=curr.dest+ydir[d];
		if(x<0 or y<0 or y>=m or x>=n){
			continue;
		}
		if(visited.count({x,y})){
			continue;
		}
		int cost;
		if(grid[curr.src][curr.dest]==1 and xdir[d]==0 and ydir[d]==1)cost=0;
		else if(grid[curr.src][curr.dest]==2 and xdir[d]==0 and ydir[d]==-1)cost=0;
		else if(grid[curr.src][curr.dest]==3 and xdir[d]==1 and ydir[d]==0)cost=0;
		else if(grid[curr.src][curr.dest]==4 and xdir[d]==-1 and ydir[d]==0)cost=0;
		else{
			cost=1;
		}
		if(cost==0){
			dq.push_front({x,y,curr.cost});
		}
		else{
			dq.push_back({x,y,curr.cost+cost});
		}
		}
	}
	return 0;
}
};