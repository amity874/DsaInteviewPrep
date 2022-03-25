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
ll cnt=0;
vector<ll> g[100005];
void dfs1(ll src,vector<bool> &visited,std::stack<ll> &st){
	visited[src]=true;
	for(auto &child:g[src]){
		if(not visited[child]){
			dfs1(child,visited,st);
		}
	}
	st.push(src);
}
void dfs2(ll src,vector<bool> visited){
visited[src]=true;
cnt++;
for(auto &child :g[src]){
	if(not visited[child]){
		dfs2(child,visited);
	}
}
}

ll getMotherVertex(ll n){
	std::stack<ll> st;
	std::vector<bool> visited(n+1,false);
	for(int i=1;i<=n;i++){
		if(visited[i]==false){
			dfs1(i,visited,st);
		}
	}
	int ans=st.top();
    loop(i,1,n){
       visited[i]=false;
   }
	dfs2(ans,visited);
	if(cnt==n){
		return ans;
	}
	return -1;
}
int main(int argc, char const *argv[]) {
// 	file_i_o();
	ll n,m;
	std::cin>>n>>m;
	loop(i,0,m-1){
		ll u,v;
		std::cin>>u>>v;
// 		log(u,v);
		g[u].push_back(v);
	}
	std::cout<<getMotherVertex(n);
	return 0;
}