class Solution {
public:
int size=0;
vector<std::string> res;
void dfs(std::unordered_map<std::string,std::vector<std::pair<std::string,bool>>>&g,vector<std::string>&ans,std::string src){
	ans.push_back(src);
	if(ans.size()==size+1){
		res=ans;
		return;
	}
	for(int i=0;i<g[src].size();i++){
		if(g[src][i].second==false){
			g[src][i].second=true;
			dfs(g,ans,g[src][i].first);
            if(not res.empty()){
                return;
            }
			g[src][i].second=false;
		}
	}
	ans.pop_back();
    return;
}
std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
    vector<std::string> ans;
    size=tickets.size();
std::unordered_map<std::string,std::vector<std::pair<std::string,bool>>> g;
   for(std::vector<std::string> ticket: tickets){
        if(g.find(ticket[0])==g.end()){
            g[ticket[0]]={};
        }
        g[ticket[0]].push_back({ticket[1],false});
    }
    for(std::unordered_map<std::string,std::vector<std::pair<std::string,bool>>>::iterator it = g.begin(); it != g.end(); it++){
        std::sort(it->second.begin(),it->second.end());
    }
    dfs(g,ans,"JFK");
    return res;
}
//     [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]] this gives the intuition for backtracking
};