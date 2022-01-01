#include <bits/stdc++.h>
#define ll long long int
std::vector<std::list<std::pair<ll,ll>>> g1;
std::vector<std::list<std::pair<ll,ll>>> g2;
ll count=1;
ll count1=1;
void mdfs(int src,std::vector<bool>&vis){
	vis[src]=true;
	for(auto &neighbour:g1[src]){
		if(!vis[neighbour.first]){
	    count+=neighbour.second;
			mdfs(neighbour.first,vis);
		}
	}
}
void mdfs1(int src,std::vector<bool>&vis){
	vis[src]=true;
	for(auto &neighbour:g2[src]){
		if(!vis[neighbour.first]){
	 count1+=1;
			mdfs(neighbour.first,vis);
		}
	}
}
int main(int argc, char const *argv[])
{
	/* code */
	ll n,m;
	std::cin>>n>>m;
	g1.resize(n,std::list<std::pair<ll,ll>>());
	g2.resize(n,std::list<std::pair<ll,ll>>());
	for(int i=0;i<m;i++){
		ll u,v,wt;
		std::cin>>u>>v>>wt;
		g1[u].push_back({v,wt});
		g2[u].push_back({v,1});
	}
	std::vector<bool>visited(n+1,false);
	mdfs(1,visited);
	visited.clear();
	mdfs1(1,visited);
	std::cout<<std::min(count,count1);
	return 0;
}