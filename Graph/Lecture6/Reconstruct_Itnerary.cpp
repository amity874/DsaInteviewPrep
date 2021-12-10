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
int size=0;
void dfs(std::unordered_map<std::string,std::vector<std::pair<std::string,bool>>>&g, std::vector<std::string>&ans,std::string src,int &chk){
    ans.push_back(src);
    if(g.find(src)!=g.end()){
        for(int i=0;i<g[src].size();i++){
            if(chk==1)return;
            if(not g[src][i].second){
            g[src][i].second=true;
            dfs(g,ans,g[src][i].first,chk);
            g[src][i].second=false;
            }
        }
    }
    if(ans.size()==size+1){
      chk=1;
    }
else{
    ans.pop_back();
}  
}
std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
    std::unordered_map<std::string,std::vector<std::pair<std::string,bool>>> g;
    std::vector<std::string>ans;
    int check=0;
    size=tickets.size();
    for(std::vector<std::string> ticket: tickets){
        if(g.find(ticket[0])==g.end()){
            g[ticket[0]]={};
        }
        g[ticket[0]].push_back({ticket[1],false});
    }
    //now we need to sort graph so that we can get lecxicographical order
    for(std::unordered_map<std::string,std::vector<std::pair<std::string,bool>>>::iterator it = g.begin(); it != g.end(); it++){
        std::sort(it->second.begin(),it->second.end());
    }
    dfs(g,ans,"JFK",check);
    return ans;
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
