class Solution {
public:
    bool dfs(int src,std::vector<int>&visited,vector<vector<int>>& graph){
        if(visited[src]!=-1){
            return visited[src];
        }
        visited[src]=0;
        for(auto &it:graph[src]){
            if(!dfs(it,visited,graph)){
                return 0;
            }
        }
        return visited[src]=1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        std::vector<int> visited(n,-1);
        std::vector<int> ans;
        for(int i=0;i<=n-1;i++){
            if(dfs(i,visited,graph)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};