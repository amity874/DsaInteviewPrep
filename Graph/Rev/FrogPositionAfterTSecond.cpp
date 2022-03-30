class Solution {
public:
double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
 std::vector<bool> visited(n+1,false);
 vector<int> g[n+1];
 for(auto &it:edges){
 	g[it[0]].push_back(it[1]);
 	g[it[1]].push_back(it[0]);
 }
std::queue<array<double,3>> q;
q.push({1.0,0,1.0});
while(not q.empty()){
	auto curr=q.front();
	q.pop();
	int node=curr[2];
	double step=curr[1];
	double prob=curr[0];
	if(visited[node]==true){
		continue;
	}
	else if(node==target){
		if(step==t){
			  return prob;
		}
	}
	visited[node]=true;
	bool has_child=false;
for(auto it:g[node]){
    if(not visited[it]){
                double next = it;
                has_child = true;
                double n = ((double)g[node].size());
                if(node!=1) n--;
                q.push({prob*1.0/n,step+1,next});
            }
}
    if(!has_child && node==target && step<=t){
     return prob;   
    }
	else if(has_child && node==target)return 0;
}
return 0;
}
};