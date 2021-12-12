#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
std::vector<ll>tree[100005];
ll dp[100005][2];
ll IndependentSet(ll node,ll parent,ll c){
	if(dp[node][c]!=-1){
		return dp[node][c];
	}
	ll w0=1;
	for(auto&c:tree[node]){
		if(c!=parent){
			w0=(w0%mod*IndependentSet(c,node,0)%mod)%mod;
		}
	}
	ll ans=0;
	ans+=w0;
	if(not c){
		ll w1=1;
		for(auto&c:tree[node]){
		if(c!=parent){
			w1=(w1%mod*IndependentSet(c,node,1)%mod)%mod;
		}
	}
	ans=(w1%mod+ans%mod)%mod;
	}
	return dp[node][c]=ans;
}
int main(int argc, char const *argv[]){
    memset(dp,-1,sizeof(dp));
    ll n;
    std::cin>>n;
    for(int i=0;i<=n-2;i++){
        ll x,y;
        std::cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    std::cout<<IndependentSet(1,-1,0);
return 0;
}