#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define MAX             300011
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	

int dp[MAX];
int indegree[MAX];
std::vector<int>g[MAX];
std::string s;
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
int Find_max(int u,int c){
	if(dp[u]!=-1){
		return dp[u];
	}
	dp[u]=0;
	for(auto &neighbour:g[u]){
		dp[u]=std::max(dp[u],Find_max(neighbour,c));
	}
	dp[u]+=(s[u-1]==(c+'a'));
	return dp[u];
}
int main(int argc, char const *argv[]) {
	file_i_o();
	memset(indegree,0,sizeof(indegree));
	int n,m;
	std::cin>>n>>m;
	std::cin>>s;
	for(int i=1;i<=m;i++){
		int u,v;
		std::cin>>u>>v;
		g[u].push_back(v);
		indegree[v]++;
	}
	int cnt=0;
	std::queue<int> qu;
	for(int i=1;i<=n;i++){
		if(indegree[i]==0){
			cnt++;
			qu.push(i);
		}
	}
	while(not qu.empty()){
		int curr=qu.front();
		qu.pop();
		for(auto &neighbour:g[curr]){
			indegree[neighbour]--;
			if(indegree[neighbour]==0){
				qu.push(neighbour);
				cnt++;
			}
		}
	}
	int ans=INT_MIN;
	if(cnt<n){
		std::cout<<-1<<"\n";
	}
	else{
		for(int c=0;c<26;c++){
	memset(dp,-1,sizeof(dp));
			for(int i=1;i<=n;i++){
				ans=std::max(ans,Find_max(i,c));
			}
		}
		std::cout<<ans<<"\n";
	}
	// logarr(dp,0,20);
	return 0;
}