class Solution {
public:
    std::vector<std::list<int>>g;
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    
    
    
    std::vector<int>res;
    if(n==1){
        res.push_back(0);
        return res;
    }
	g.resize(n,std::list<int>());
	std::vector<int> indegree(n,0);
	for(auto &ch:edges){
		g[ch[0]].push_back(ch[1]);
		g[ch[1]].push_back(ch[0]);
		indegree[ch[0]]++;
		indegree[ ch[1]]++;
	}
	std::queue<int> qu;
	for(int i=0;i<=n-1;i++){
		if(indegree[i]==1){
			qu.push(i);
			indegree[i]--;
		}
	}
	while(not qu.empty()){
		int s=qu.size();
		res.clear();
		for(int i=0;i<s;i++){
			int tp=qu.front();
			qu.pop();
			res.push_back(tp);
			for(auto&it:g[tp]){
				indegree[it]--;
				if(indegree[it]==1){
					qu.push(it);
				}
			}
		}
	}
	return res;
}
};