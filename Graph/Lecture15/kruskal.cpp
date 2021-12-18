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
struct Edge{
    ll src;
    ll dest;
    ll wt;
};
ll Get(vi &parent, int a) {
    return parent[a] = ((parent[a] == a) ? a : Get(parent, parent[a]));
}
void Union(vi &parent, vi &rank, ll a, ll b) {
    a = Get(parent, a);
    b = Get(parent, b);
    if(rank[a] == rank[b]) {
        rank[a]++;
    }
    if(rank[a] > rank[b]) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}
bool cmp(Edge e1,Edge e2){
    return e1.wt<e2.wt;
}
std::vector<Edge> kruskals(Edge *inp, int n, int e) {
    std::sort(inp, inp+e, cmp);
    vi parent(n+1);
    vi rank(n+1, 0);
    loop(i, 0, n) parent[i] = i;
    std::vector<Edge> result;
    for(int i=0;i<e;i++){
        int l1=Get(parent,inp[i].src);
        int l2=Get(parent,inp[i].dest);
        // checking for cycle
        if(l1!=l2){
            result.push_back({inp[i].src,inp[i].dest,inp[i].wt});
            Union(parent,rank,inp[i].src,inp[i].dest);
        }
    }
    return result;
}
int main(int argc, char const *argv[])
{
return 0;
}