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
std::vector<int>g[100050];
bool visited[100050];
std::stack<int> st;
std::vector<int>result;
void dfs(int src,int parent){
	visited[src]=true;
	st.push(src);
	for(auto child:g[src]){
		if(child!=parent){
			if(not visited[child]){
				dfs(child,src);
			}else if(result.size()==0){
				result.push_back(child);
				while(not st.empty()&& st.top()!=child){
					result.push_back(st.top());
					st.pop();
				}
				result.push_back(child);
			}
		}
	}
	if(st.top()==src){
		st.pop();
	}
}
int main(int argc, char const *argv[]) {
	file_i_o();
	int a,b;
	std::cin>>a>>b;
	for(int i=1;i<=b;i++){
		int u,v;
		std::cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(visited,false,sizeof(visited));
	for(int i=1;i<=a;i++){
		if(not visited[i]){
			dfs(i,-1);
		}
	}
	if(result.size()){
		std::cout<<result.size()<<"\n";
		for(auto &el:result){
			std::cout<<el<<" ";
		}
	}else{
		std::cout<<"IMPOSSIBLE"<<"\n";
	}
	return 0;
}