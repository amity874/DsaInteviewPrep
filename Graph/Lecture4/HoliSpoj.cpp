// https://www.spoj.com/problems/HOLI/
//icpc problem
#include<bits/stdc++.h>
#define ll long long int
std::vector<std::list<std::pair<ll,ll>>> graph;
ll ans=0;
int cs=1;
ll helper(std::vector<ll>&count,std::vector<bool>&vis,ll node,ll n,ll &ans){
    count[node]=1;
    vis[node]=true;
    for(auto &neighbour:graph[node]){
        ll curr=neighbour.first;
        ll wight=neighbour.second;
        if(not vis[curr]){
            count[node]+=helper(count,vis,curr,n,ans);
            ans+=2*wight*std::min(count[curr],n-count[curr]);
        }
    }
    return count[node];
}
ll dfs(ll n){
    std::vector<bool>vis(n,false);
    std::vector<ll>count(n,0);
    ll ans=0;
    helper(count,vis,0,n,ans);
    return ans;
}
int main(int argc, char const *argv[])
{
int t;
std::cin>>t;
while(t--){
    ll n;
    std::cin>>n;
    graph.resize(n,std::list<std::pair<ll,ll>>());
    for(int i=0;i<n-1;i++){
        ll u;
        ll v;
        ll wt;
        std::cin>>u>>v>>wt;
        u--;
        v--;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }
    std::cout<<"Case #"<<cs++<<": "<<dfs(n)<<"\n";
    graph.clear();
}
return 0;
}