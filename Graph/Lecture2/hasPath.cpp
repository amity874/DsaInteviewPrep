class Solution {
public:
    std::vector<std::vector<int>> res;
void Helper(int src,int dest,vector<vector<int>>& graph,std::vector<bool> &visited,std::vector<int> &path){
    visited[src]=true;
    path.push_back(src);
    if(src==dest){
        res.push_back(path);
    }
    for(auto &n:graph[src]){
        if(not visited[n]){
            Helper(n,dest,graph,visited,path);
        }
    }
    path.pop_back();
    visited[src]=false;
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
 int n=graph.size();
std::vector<bool> vis(n);
std::vector<int> path;
std::vector<bool>visited(n,0);
Helper(0,n-1,graph,visited,path);
        return res;
    }
};