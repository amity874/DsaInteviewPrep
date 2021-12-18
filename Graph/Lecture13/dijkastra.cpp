#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define ip(x)           int x;cin>>x
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
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
 
const int N = 1e5 + 5;
vector<pii> adj[N];
int n, m;
vi dijkstra(int src){
    vi dist(n+1,inf);
    dist[src]=0;
    std::set<std::pair<int,int>> st;
    st.insert({0,src});//{dist,node}
    while(not st.empty()){
        int curr=st.begin()->second;
        st.erase(st.begin());
        for(auto &n:adj[curr]){
            int node=n.first;
            int wt=n.second;
            if(dist[curr]+wt<dist[node]){
                st.erase({dist[node],node});
                dist[node]=dist[curr]+wt;
                st.insert({dist[node],node});
            }
        }
    }
    return dist;
}
int32_t main()
{
	file_i_o();
	cin >> n; 
	w(m)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	vi d = dijkstra(1);
 
	for(int i=1; i<=n; i++)
		cout << i << '\t' << d[i] << "\n";
 
	return 0;
}
 