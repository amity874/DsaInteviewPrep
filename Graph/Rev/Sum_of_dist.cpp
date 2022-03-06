class Solution {
public:
int dp[30008];
int sz[30008];
vector<int> graph[30008];
void f(int src,int par){
    sz[src]=1;
    for(auto child:graph[src]){
        if(child!=par){
            f(child,src);
            sz[src]+=sz[child];
            dp[src]+=dp[child]+sz[child];
        }
    }
}
void g(int src,int par,int n,vector<int> &ans){
    if(src==par){
        ans[src]=dp[src];
    }
    else{
        ans[src]=((ans[par]-sz[src]+(n-sz[src])));
    }
    for(auto &child:graph[src]){
        if(child!=par){
            g(child,src,n,ans);
        }
    }
}
vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    vector<int> ans(n,0);
    for(auto e:edges){
        // cout<<e[0]<<"  "<<e[1]<<" ";
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    f(0,-1);
    g(0,0,n,ans);
    return ans;
}
};