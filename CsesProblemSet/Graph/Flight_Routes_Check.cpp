#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define us              unordered_set
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
vector<int>g[100005];
vector<int>gt[100005];
vector<int> component;
std::stack<int>st;
vector<bool>visited;
void dfs1(int i){
    visited[i]=true;
    for(auto &neighbour:g[i]){
        if(not visited[neighbour]){
            dfs1(neighbour);
        }
    }
    st.push(i);
}
void dfs2(int i){
    visited[i]=true;
    component.push_back(i);
    for(auto &neighbour:gt[i]){
        if(not visited[neighbour]){
            dfs2(neighbour);
        }
    }
}
vector<int> getSCC(int n,int e){
	visited.assign(n+1,false);
    for(int i=1;i<=n;i++){
        if(not visited[i]){
            dfs1(i);
        }
    }
    visited.assign(n+1,false);
    vector<int>result;
    while(not st.empty()){
        int res=st.top();
        st.pop();
        if(!visited[res]){
        dfs2(res);
        result.push_back(component[0]);
        component.clear();
    }
    }
    return result;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	ll n,m;
	std::cin>>n>>m;
	loop(i,1,m){
		ll u,v;
		cin>>u>>v;
		g[u].push_back(v);
		gt[v].push_back(u);
	}
	vector<int> ans=getSCC(n,m);
	if(ans.size()>1){
		std::cout<<"NO"<<"\n";
		std::cout<<ans[1]<<" "<<ans[0]<<"\n";
	}
	else{
		std::cout<<"YES"<<"\n";
	}
	return 0;
}