#include<bits/stdc++.h>
// --===Amit pandey--===
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
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
std::vector<std::vector<pair<int,int>>> g;
int level(int n,int m,char d,int i,int j){
    if(d=='U'){
        i--;
    }
    else if(d=='L'){
        j--;
    }
    else if(d=='R'){
        j++;
    }
    else{
        i++;
    }
    if(i<0 or j<0 or i>=n or j>=m){
        return -1;
    }
    return (i*m+j);
}
char dir(int d){
    if(d==0){
        return 'L';
    }
    else if(d==1){
        return 'U';
    }
    else if(d==2){
        return 'R';
    }
    else if(d==3){
        return 'D';
    }
}
int bfs(int n,int m){
    std::vector<int>dist(n*m,INT_MAX);
    std::deque<int>dq;
    int src=0;
    int dest=((n-1)*(m)+(m-1));
    dist[src]=0;
    dq.push_back(src);
    while(not dq.empty()){
        int p=dq.front();
        dq.pop_front();
        for(auto &n:g[p]){
            if(dist[n.first]>dist[p]+n.second){
                dist[n.first]=dist[p]+n.second;
                if(n.second==0){
                    dq.push_front(n.first);
                }
                else{
                    dq.push_back(n.first);
                }
            }
        }
    }
    return dist[dest];
}
int minmodification(std::vector<std::vector<char>> &mat,int n,int m){
g.resize(n*m);
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        for(int d=0;d<4;d++){
          int lv=level(n,m,dir(d),i,j);
          if(lv==-1){
              continue;
          }
          if(mat[i][j]==dir(d)){
              g[(i*m)+j].push_back({lv,0});
          }
          else{
              g[(i*m)+j].push_back({lv,1});
          }
        }
    }
}
// for(auto v:g){
//     for(auto el:v){
//         std::cout<<el.first<<" ->"<<el.second<<" ";
//     }
//     std::cout<<"\n";
// }
return bfs(n,m);
}
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int n,m;
	cin >> n>>m;
    std::vector<std::vector<char>> mat(n,std::vector<char>(m,' '));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin>>mat[i][j];
        }
    }
    std::cout<<minmodification(mat,n,m);
	return 0;
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
}
