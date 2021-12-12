// https://cses.fi/problemset/task/1674
#include<bits/stdc++.h>
#define ll long long int
std::vector<ll>g[200005];
ll dp[200005];
ll f(ll src,ll p){
    if(dp[src]!=-1){
        return dp[src];
    }
     ll ans=0;
    for(auto &c:g[src]){
        if(c!=p){
        ans+=1+f(c,src);
        }
        // dp[c]=ans;
    }
    return dp[src]=ans;
}
int main(int argc, char const *argv[])
{
    ll n;
    std::cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=2;i<=n;i++){
        ll x;
        std::cin>>x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    f(1,-1);
    for(int i=1;i<=n;i++){
        std::cout<<dp[i]<<" ";
    }
return 0;
}
