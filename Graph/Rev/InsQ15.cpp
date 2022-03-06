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
# define mx  100005
ll H[2*mx+10];
ll C[2*mx+10];
vector<ll> dist(2*mx+10,inf);
vector<bool> vis(2*mx+10,false);
std::vector<std::vector<pair<ll,ll>>> g;
int main(int argc, char const *argv[]) {
	file_i_o();
	ll n,r;
	std::cin>>n>>r;
	g.resize(2*mx+10,vector<pair<ll,ll>>());
	for(int i=1;i<=n;i++){
		std::cin>>H[i];
	}
	for(int i=1;i<=n;i++){
        std::cin>>C[i];
        g[i].push_back({n+i,C[i]});
        g[n+i].push_back({i,C[i]});
    }
	for(int i=1;i<=r;i++){
		ll u,v;
		std::cin>>u>>v;
		if(H[u]<=H[v]){
			g[u].push_back({v,0});
		}
		if(H[u]>=H[v]){
			g[n+u].push_back({n+v,0});
		}
		if(H[v]<=H[u]){
			g[v].push_back({u,0});
		}
		if(H[v]>=H[v]){
			g[n+v].push_back({n+u,0});
		}
	}
	//setting up the node
	g[0].push_back({1,C[1]});
	g[0].push_back({n+1,C[1]});
	g[n].push_back({2*n+1,0});//last dummy node
	g[2*n].push_back({2*n+1,0});// last dummy node
	std::set<pair<ll,ll>> st;
	dist[0]=0;
	st.insert({0,0});
	while(not st.empty()){
		pair<ll,ll> tp=*(st.begin());
		ll idx=tp.second;
		st.erase(st.begin());
		for(auto & child:g[idx]){
		 if(vis[child.first]){
			continue;
		}
		visited[idx]=true;
		if(dist[child.first]>dist[idx]+child.second){
			dist[child.first]=dist[idx]+child.second;
			st.insert({dist[child.first],child.first});
		}
		}
	}
	if(dist[2*n+1]==INT_MAX){
		std:cout<<"-1"<<"\n";
	}
	else{
		std::cout<<dist[2*n+1]<<"\n";
	}
	return 0;
}