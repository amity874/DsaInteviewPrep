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
ll Get(vi &parent,ll a){
    return parent[a]=((parent[a]==a)?a:Get(parent,parent[a]));
}
int Union(vi &parent,vi &rank,ll a,ll b){
    a=Get(parent,a);
    b=Get(parent,b);
    if(a==b){
    	return false;
    }
    if(rank[a]>rank[b]){
        parent[b]=a;
        rank[a]+=rank[b];
    }
    else{
        parent[a]=b;
        rank[b]+=rank[a];
    }
    return max(rank[a],rank[b]);
}
int main(int argc, char const *argv[]) {
	file_i_o();
	ll n,m;
	std::cin>>n>>m;
	vector<ll> parent(n+1);
	vector<ll>size(n+1,1);
	loop(i,1,n){
		parent[i]=i;
	}
	ll connected_component=n;
	ll sz=1;
	loop(i,1,m){
		ll u,v;
		cin>>u>>v;
		if(!Union(parent,size,u,v)){
			int x1=Union(parent,size,u,v);
			connected_component--;
			sz=std::max(sz,x1);
		}
		std::cout<<connected_component<<" "<<sz<<"\n";
	}
	return 0;
}