class Solution {
public:
std::vector<int>dp;
std::unordered_map<int,std::vector<int>>graph;
int  dfs(int src,vector<int>& quiet){
	if(dp[src]!=-1){
		return dp[src];
	}
	int Min=src;
	for(auto& it:graph[src]){
        int res=dfs(it,quiet);
		if(quiet[res]<quiet[Min]){
            Min=res;
		}
	}
	return dp[src]=Min;
}
vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet){
	    int n=quiet.size();
        for(auto el:richer){
        	int u=el[1];
        	int v=el[0];
        	graph[u].push_back(v);
        }
        dp.resize(n,-1);
        for(int i=0;i<n;i++){
        	dfs(i,quiet);
        }
        return dp;
}
};