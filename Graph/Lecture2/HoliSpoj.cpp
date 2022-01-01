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
int c=0;
std::vector<std::list<std::pair<ll,ll>>> g;
ll dfsHelper(int src,std::vector<bool>&visited,std::vector<int>&count,ll &ans,int n){
	count[src]=1;
	visited[src]=true;
	for(auto &neighbour:g[src]){
		if(!visited[neighbour.first]){
			count[src]+=dfsHelper(neighbour.first,visited,count,ans,n);
			ans+=2*neighbour.second*std::min(count[neighbour.first],n-count[neighbour.first]);
		}
	}
	return count[src];
}
ll dfs(int n){
	std::vector<bool>visited(n,false);
	std::vector<int>count(n,0);
	ll ans=0;
	dfsHelper(0,visited,count,ans,n);
	return ans;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	ll t;
	std::cin>>t;
	while(t--){
	    ll n;
		std::cin>>n;
		g.resize(n,std::list<std::pair<ll,ll>>());
		for(int i=0;i<n-1;i++){
			ll u;
			ll v;
			ll wt;
			std::cin>>u>>v>>wt;
			u--;
			v--;
			g[u].push_back({v,wt});
			g[v].push_back({u,wt});
		}
	std::cout<<"Case #"<<++c<<":"<<dfs(n)<<"\n";
	g.clear();
	}
	return 0;
}