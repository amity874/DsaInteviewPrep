// https://www.codechef.com/problems/DIGJUMP
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
std::vector<ll>g[100005];
ll bfs(ll src,ll n,std::string str){
    std::vector<bool>vis(n,false);
std::vector<int>dist(n,0);
    std::queue<ll>qu;
    qu.push(0);
    dist[src]=0;
    while(not qu.empty()){
        int tp=qu.front();
        qu.pop();
        if(tp==n-1)break;
        int val=str[tp]-'0';
        int sz=g[val].size();
        for(int i=0;i<sz;i++){
            int idx=g[val][i];
            if(not vis[idx]){
                vis[idx]=true;
                qu.push(idx);
                dist[idx]=dist[tp]+1;
            }
        }
        g[val].clear();
        if(tp-1>=0 && !vis[tp-1]){
            qu.push(tp-1);
            vis[tp-1]=true;
            dist[tp-1]=dist[tp]+1;
        }
        if(tp+1<n && !vis[tp+1]){
            qu.push(tp+1);
            vis[tp+1]=true;
            dist[tp+1]=dist[tp]+1;
        }
    }
    return dist[n-1];
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
    std::string s;
    std::cin>>s;
    int n=s.size();
    for(int i=1;i<n;i++){
        g[s[i]-'0'].push_back(i);
    }
    std::cout<<bfs(0,n,s);
	return 0;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
