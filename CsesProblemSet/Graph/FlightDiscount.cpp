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
struct e{
	ll v,wt;
	bool operator <(e const& other){
		return wt<other.wt;
	}
};
vi dijkstra(int src,ll n,vector<vector<e>>&g){
	vector<ll>dist(n+1,inf);
	vector<bool>visited(n+1,false);
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
	dist[src]=0;
	pq.push({0,src});//dist,node
	while(not pq.empty()){
		ll tp=pq.top().second;
		pq.pop();
		if(visited[tp]){
			continue;
		}
		visited[tp]=true;
		for(auto it:g[tp]){
			if(dist[tp]+it.wt<dist[it.v]){
				dist[it.v]=dist[tp]+it.wt;
				pq.push({dist[it.v],it.v});
			}
		}
	}
	return dist;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	ll n,m;
	std::cin>>n>>m;
	vector<vector<ll>>edges;
	vector<vector<e>>adjf(n+1);
	vector<vector<e>>adjr(n+1);
	for(int i=1;i<=m;i++){
		ll u,v,wt;
		std::cin>>u>>v>>wt;
		edges.push_back({u,v,wt});
		adjf[u].push_back({v,wt});
		adjr[v].push_back({u,wt});
	}
	vi ans1=dijkstra(1,n,adjf);
	vi ans2=dijkstra(n,n,adjr);
	// logarr(ans1,1,n);
	// logarr(ans2,1,n);
	ll ans=ans1[n];
	for(auto el:edges){
		ans=std::min(ans,ans1[el[0]]+ans2[el[1]]+el[2]/2);
	}
	std::cout<<ans<<"\n";
	return 0;
}