#include<bits/stdc++.h>
#define pii  std::pair<int,int>

std::vector<std::list<std::pair<int,int>>>g;
std::vector<pii> prims(int src,int n){
    std::priority_queue<pii,std::vector<pii>,std::greater<pii>> pq;
    std::vector<pii>result;
    std::vector<bool>visited(n+1,0);
    visited[src]=true;
    pq.push(std::make_pair(0,src));
    while(not pq.empty()){
        int tp=pq.top().second;
        auto ans=pq.top();
        pq.pop();
        if(visited[tp]){
            continue;
        }
        result.push_back(ans);
        visited[tp]=true;
        for(auto child:g[tp]){
            if(not visited[child.second]){
                pq.push(child);
            }
        }
    }
    return result;
}
int main(int argc, char const *argv[])
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
return 0;
}