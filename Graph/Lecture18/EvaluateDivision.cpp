#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string,std::list<std::pair<string,double>>>g;
double dfsHelper(std::string src,std::string dest,std::set<std::string> vis){
   if((g[src].begin()==g[src].end() or  g[dest].begin()==g[dest].end())){
		return -1.0;
	}
	if(src==dest){
		return 1.0;
	}
	vis.insert(src);
	for(auto & neighbour:g[src]){
		auto search = vis.find(neighbour.first);
		if(search==vis.end()){
			double res=dfsHelper(neighbour.first,dest,vis);
			if(res!=-1.0){
				return res*neighbour.second;
			}
		}
	}
	return -1.0;
} 
std::vector<double> Helper(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries){
	int n=equations.size();
	int m=equations[1].size();
	std::vector<double> result(queries.size());
	std::set<std::string>vis;
	for(int i=0;i<queries.size();i++){
		result[i]=dfsHelper(queries[i][0],queries[i][1],vis);
	}
	return result;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
int n=equations.size();
int m=equations[0].size();
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		std::string s1=equations[i][0];
		std::string s2=equations[i][1];
		g[s1].push_back({s1,values[0]});
		g[s2].push_back({s1,1/values[0]});
	}
}
std::vector<double>res(n);
 res=Helper(equations,values,queries);
 return res;
}