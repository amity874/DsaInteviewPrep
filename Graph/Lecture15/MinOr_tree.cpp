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
class DSU{
	std::vector<int> rank;
	std::vector<int> parent;
public:
	DSU(int n){
		for(int i=0;i<=n;i++){
			rank.push_back(0);
			parent.push_back(i);
		}
	}
	int Get(int a){
		if(a==parent[a]){
			return a;
		}
		int leader=Get(parent[a]);
		parent[a]=leader;
		return leader;
	}
	void Union(int a,int b) {
		a=Get(a);
		b=Get(b);
		if(rank[a]==rank[b]){
			rank[a]++;
		}
		if(rank[a]>rank[b]){
			parent[b]=a;
		}
		else{
			parent[a]=b;
		}
	}
};
void  solve(){
	ll n;
	ll m;
	std::cin>>n>>m;
std::vector<std::pair<std::pair<ll,ll>,ll>>g;
		for(int i=0;i<m;i++){
			ll u;
			ll v;
			ll wt;
			std::cin>>u>>v>>wt;
			g.push_back({{u,v},wt});
		}
	ll ans=0;
	ll ones=-1;//represent in binary will be 111111.....1111
	for(int bit=32;bit>=0;bit--){
		DSU d(n);
		int cnt=0;
		for(auto &ne:g){
			ll wt=ne.second;
			ll u=ne.first.first;
			ll v=ne.first.second;
			ll prefix=wt & (ones << bit);
			ll res=ans|  prefix;
			// log(wt,u,v,prefix,res);
			if(res!=ans){
				continue;
			}
			if(d.Get(u)==d.Get(v)){
				continue;
			}
			cnt++;
			d.Union(u,v);
		}
		if(cnt!=n-1){
			ans^=(1<<bit);
		}
	}
	std::cout<<ans<<"\n";
}

int main(int argc, char const *argv[]) {
	file_i_o();
	int t;
	std::cin>>t;
	while(t--){
		solve();
	}
	return 0;
}