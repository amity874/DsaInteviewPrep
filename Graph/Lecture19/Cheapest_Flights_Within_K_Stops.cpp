#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				emplace_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
#define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
	std::vector<std::vector<std::pair<int,int>>> g;
int dp[110][110];
int modified_dfs(int src,int dest,int k){
	if(src==dest){
		return 0;
	}
	if(k<0){
		return INT_MAX;
	}
	if(dp[src][k]!=-1){
		return dp[src][k];
	}
	int ans=INT_MAX;
	for(auto &childreen:g[src]){
		int node=childreen.first;
		int wt=childreen.second;
		int temp=modified_dfs(node,dest,k-1);
		if(temp!=INT_MIN){
			ans=std::min(ans,wt+temp);
		}
	}
	return dp[src][k]=ans;
}
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
	memset(dp,-1,sizeof(dp));
	g.resize(n,std::vector<std::pair<int,int>>());
	for(auto &it:flights){
		int u=it[0];
		int v=it[1];
		int wt=it[2];
		g[u].push_back({v,wt});
	}
	int ans=modified_dfs(src,dst,k);
	if(ans!=INT_MAX){
		return ans;
	}
	return -1;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}