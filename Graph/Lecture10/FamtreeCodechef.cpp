#include<bits/stdc++.h>
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;
ll ans = 0;
vector<vector<ll> > graph(100005);
ll w[100005], p[100005];
ll ma[100005], mi[100005];
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


void famtree(ll i, ll par) {
	for(ll child:graph[i]){
		if(child!=par){
			famtree(child,i);
			ma[i]=std::max({ma[i],ma[child]});
			mi[i]=std::min({mi[i],mi[child]});
		}
	}
	ma[i]=std::max({ma[i],w[i]});
	mi[i]=std::min({mi[i],w[i]});
	ans=std::max(ans,abs(w[i]-ma[i]));
	ans=std::max(ans,abs(w[i]-mi[i]));
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	// file_i_o();
	// Write your code here....
	ll n;
	std::cin>>n;
	loop(i, 1, n) {
		ma[i] = -inf;
		mi[i] = inf;
	}
	ll root = 0;
	loop(i, 1, n) std::cin>>w[i];
	loop(i, 1, n) {
		std::cin>>p[i];
		if(p[i]==-1){
			root=i;
		}
		else{
		   graph[p[i]].push_back(i);
		}
	}
	famtree(root, 0);
	std:cout<<ans;
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}