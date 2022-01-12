class Solution {
public:
    struct st{
	int node,color,dist;
};
std::vector<std::list<int>>red;
std::vector<std::list<int>>green;
void m_bfs(int src,int n,std::vector<int>&dist){
	std::queue<st> q;
    q.push({0,0,0});
	q.push({0,1,0});
	std::unordered_map<int,int> r;
	std::unordered_map<int,int> g;
	r[0]=1;
	g[0]=1;
	dist[src]=0;
	while(not q.empty()){
		int curr=q.front().node;
		int c=q.front().color;
		int d=q.front().dist;
		q.pop();
		if(c==0){
		for(auto childreen:red[curr]){
		if(r.count(childreen)==0){
			r[childreen]=1;
			dist[childreen]=std::min(dist[childreen],d+1);
			q.push({childreen,c^1,d+1});
		}
		}
	    }
	    else{
	    	for(auto childreen:green[curr]){
		if(g.count(childreen)==0){
			g[childreen]=1;
			dist[childreen]=std::min(dist[childreen],d+1);
			q.push({childreen,c^1,d+1});
		}
	    }
	}
}
}
vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>&blue_edges) {
	red.resize(n,std::list<int>());
	green.resize(n,std::list<int>());
	for(int i=0;i<red_edges.size();i++){
		red[red_edges[i][0]].push_back(red_edges[i][1]);
	}
	for(int i=0;i<blue_edges.size();i++){
		green[blue_edges[i][0]].push_back(blue_edges[i][1]);
	}
	std::vector<int>dist(n,INT_MAX);
	m_bfs(0,n,dist);
	std:vector<int>ans;
	for(int i=0;i<n;i++){
		if(dist[i]==INT_MAX){
			ans.push_back(-1);
		}
		else{
			ans.push_back(dist[i]);
		}
	}
	return ans;
}
};