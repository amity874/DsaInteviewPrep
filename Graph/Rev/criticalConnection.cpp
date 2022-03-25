class Solution {
public:
vector<bool> visited;
vector<int> parent;
vector<int> low;
vector<int> disc;
int timer=0;
vector<vector<int>> ans;
    void dfs(int src,vector<vector<int>> &g){
        low[src]=timer;
        disc[src]=timer;
        timer++;
        visited[src]=true;
        vector<int> nbr=g[src];
        for(int i=0;i<nbr.size();i++){
            int v=nbr[i];
            if(parent[src]==v){
                continue;
            }
            else if(visited[v]==true){
                low[src]=std::min(low[src],disc[v]);
            }
            else{
                parent[v]=src;
                dfs(v,g);
                low[src]=std::min(low[src],low[v]);
                if(low[v]>disc[src]){
                    std::vector<int> temp;
                    temp.push_back(src);
                    temp.push_back(v);
                    ans.push_back(temp);
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        visited.resize(n,false);
        low.resize(n);
        disc.resize(n);
        parent.resize(n);
        for(auto &nbr:connections){
            graph[nbr[0]].push_back(nbr[1]);
            graph[nbr[1]].push_back(nbr[0]);
        }
        dfs(0,graph);
        return ans;
    }
};