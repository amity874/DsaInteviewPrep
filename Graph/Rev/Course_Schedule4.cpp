class Solution {
public:
 vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
	// int n=prerequisites.size();
	// int m=prerequisites[0].size();
	vector<int> indegree(n);
	vector<bool> ans;
	vector< bitset<101>> prevs(n);
	vector<vector<int> > g(n);
	for(auto &it:prerequisites){
        indegree[it[1]]++;
		g[it[0]].push_back(it[1]);
	}
	std::queue<int> qu;
	for(int i=0;i<n;i++){
		if(indegree[i]==0){
			qu.push(i);
		}
         prevs[i].set(i,1);
	}
	while(not qu.empty()){
		int tp=qu.front();
        qu.pop();
		for(auto &it:g[tp]){
			prevs[it]|=prevs[tp];
			indegree[it]--;
			if(indegree[it]==0){
			qu.push(it);
		}
		}
	}
	for(auto &it:queries){
		ans.push_back(prevs[ it[1] ].test( it[0] ));
	}
	return ans;   
    }
};