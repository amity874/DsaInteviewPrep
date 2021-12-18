// https://www.codechef.com/problems/DIGJUMP
#include<bits/stdc++.h>
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             100000000000000
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
template <typename T> T gcd(T a, T b) {if (a % b) return gcd(b, a % b); return b;}
template <typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}
vs tokenizer(string str, char ch) {std::istringstream var((str)); vs v; string t; while (getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
}
#define mx 100005
ll dist[2*mx+10];
bool visited[2*mx+10];
ll h[mx+10];
ll c[mx+100];
std::vector<std::vector<pair<ll,ll>>> g;
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
    ll n,r;
    std::cin>>n>>r;
    g.resize(2*mx+10,std::vector<pair<ll,ll>>());
    for(int i=1;i<=2*n+5;i++){
        dist[i]=inf;
        visited[i]=false;
    }
    for(int i=1;i<=n;i++){
        std::cin>>h[i];
    }
    for(int i=1;i<=n;i++){
        std::cin>>c[i];
        g[i].push_back({n+i,c[i]});
        g[n+i].push_back({i,c[i]});
    }
    for(int i=1;i<=r;i++){
        ll x,y;
        std::cin>>x>>y;
        if(h[x]<=h[y]){
            g[x].push_back({y,0});
        }
        if(h[x]>=h[y]){
            g[n+x].push_back({n+y,0});
        }
        if(h[y]<=h[x]){
            g[y].push_back({x,0});
        }
        if(h[y]>=h[x]){
            g[n+y].push_back({n+x,0});
        }
    }
    //setting up the dummy node
    g[0].push_back({1,c[1]});
    g[0].push_back({n+1,c[1]});
    g[n].push_back({2*n+1,0});
    g[2*n].push_back({2*n+1,0});
    std::set<std::pair<ll,ll>> st;
	g[0].pb({1, c[1]});
	g[0].pb({n + 1, c[1]});
	g[n].pb({2 * n + 1, 0});
	g[2 * n].pb({2 * n + 1, 0});
	dist[0] = 0;
	st.insert({0, 0});
	while (!st.empty()) {
		pair<ll, ll> top = *(st.begin());
		ll vert;
		vert = top.second;
		st.erase(st.begin());
		if (visited[vert])continue;
		visited[vert] = 1;
		for (auto child : g[vert]) {
			if (visited[child.first])continue;
			if (dist[child.first] > dist[vert] + child.second){
				dist[child.first] = dist[vert] + child.second;
				st.insert({dist[child.first], child.first});
			}
		}
	}
	if (dist[2 * n + 1] == inf) {
		cout << -1 <<"\n";
	}
	else {
		cout << dist[2 * n + 1] <<"\n";
	}
	return 0;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
