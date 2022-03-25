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
vector<ll> g[1005];
vector<bool> ap(1005,false);
vector<bool> visited(1005,false);
vector<ll> parent(1005);
vector<ll> low(1005,INT_MAX);
vector<ll> disc(1005,INT_MAX);//represent discovery time of a node
int timer=0;
void getAp(ll node){
	disc[node]=timer;
	low[node]=timer;
	timer++;
	int cnt=0;
	visited[node]=true;
	vector<ll> nbr=g[node];
	for(int i=0;i<nbr.size();i++){
		ll v=nbr[i];
		if(parent[node]==v){
			continue;
		}
		else if(visited[v]==true){
			low[node]=std::min(low[node],disc[v]);
		}
		else{
			parent[v]=node;
		    cnt++;
			getAp(v);
			low[node]=std::min(low[node],low[v]);
			if(parent[node]==-1){
				if(cnt>=2){
					ap[node]=true;
				}
			}
			else{
				if(low[v]>=disc[node]){
					ap[node]=true;
				}
			}
		}
	}
}
int main(int argc, char const *argv[]) {
	// file_i_o();
	parent[0]=-1;
	int n,e;
	std::cin>>n>>e;
	loop(i,1,e){
		ll u,v;
		std::cin>>u>>v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u); 
	}
	getAp(0);
	int ans=0;
	loop(i,0,n-1){
		if(ap[i]==true){
			ans++;
		}
	}
// 	logarr(ap,0,n-1);
	std::cout<<ans<<"\n";
	return 0;
}