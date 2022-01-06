class Solution {
public:
   int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
	std::vector<std::vector<std::pair<int,int>>> g(n);
	for(auto &it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        g[u].push_back({v,wt});
        g[v].push_back({u,wt});
    }
	std::vector<int> dist(n,INT_MAX);
	dist[0]=0;
	std::set<std::pair<int,int>> st;
	st.insert({0,0});
	while(not st.empty()){
		int curr=st.begin()->second;
		st.erase(st.begin());
		for(auto &el:g[curr]){
			int node=el.first;
			int wt=el.second+1;
			if(dist[curr]+wt<dist[node]){
				st.erase({dist[node],node});
				dist[node]=dist[curr]+wt;
				st.insert({dist[node],node});
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;++i){
		if(dist[i]<=maxMoves){
			ans++;
		}
	}
	for(auto &it:edges){
		int u=it[0];
		int v=it[1];
		int between=it[2];
		int x=std::max(0,(maxMoves-dist[u]));
		int y=std::max(0,(maxMoves-dist[v]));
		ans+=std::min(between,(x+y));
	}
	return ans;
}
};