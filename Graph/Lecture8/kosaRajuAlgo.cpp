#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define nl				"\n"
#define pb 				push_back
#define eb				emplace_back
#define vi              std::vector<ll>
#define vs				std::vector<std::string>
#define pii             std::pair<ll,ll>
#define ump				std::unordered_map
#define mp 				std::make_pair
#define pq_max          std::priority_queue<ll>
#define pq_min          std::priority_queue<ll,vi,std::greater<ll> >
#define all(n) 			n.begin(),n.end()
#define us              std::unordered_set
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(std::string str,char ch) {std::istringstream var((str)); vs v; std::string t; while(std::getline((var), t, (ch))) {v.pb(t);} return v;}
std::vector<std::list<int>>g;
std::vector<std::list<int>>gt;//graph transpose
void dfs1(int i,us<int>&visited,std::stack<int>&st){
    visited.insert(i);
    for(auto &neighbour:g[i]){
        if(not visited.count(neighbour)){
            dfs1(neighbour,visited,st);
        }
    }
    st.push(i);
}
void dfs2(int i,us<int>&visited,us<int>&temp){
    visited.insert(i);
    temp.insert(i);
    for(auto &neighbour:gt[i]){
        if(not visited.count(neighbour)){
            dfs2(neighbour,visited,temp);
        }
    }
}
std::vector<us<int>> getSCC(int n,int e){
    std::stack<int>st;
    us<int> visited;
    for(int i=0;i<n;i++){
        if(not visited.count(i)){
            dfs1(i,visited,st);
        }
    }
    visited.clear();
    std::vector<us<int>> result;
    while(not st.empty()){
        int res=st.top();
        st.pop();
        if( visited.count(res))continue;
        us<int>temp;
        dfs2(res,visited,temp);
        result.emplace_back(temp);
    }
    return result;
}
int main(int argc, char const *argv[])
{
    int v,e;
    std::cin>>v>>e;
    g.resize(v,std::list<int>());
    gt.resize(v,std::list<int>());
    for(int i=0;i<e;i++){
        int u,v;
        std::cin>>u>>v;
        g[u].push_back(v);
        gt[v].push_back(u);
    }
    std::vector<us<int>> res=getSCC(v,e);
    for(auto&s:res){
        for(auto&el:s){
            std::cout<<el<<" , ";
        }
        std::cout<<"\n";
    }
return 0;
}