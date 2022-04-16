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
int getCnt(map<char,std::set<char>> &g,char src,map<char,int> &ans){
	if(not g.count(src)){
		ans[src]=0;
		return 1;
	}
	int res=0;
	for(auto &it:g[src]){
		// cout<<it;
		res+=getCnt(g,it,ans);
	}
	ans[src]=res;
	return res+1;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	map<char,std::set<char>> g;
	map<char,int> ans;
	char root;
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++){
		char str1;
		char str2;
		std::cin>>str1;
		std::cin>>str2;
		if(str2==str1){
			root=str2;
		}
		else{
			g[str2].insert(str1);
		}
	}
	getCnt(g,root,ans);
	for(auto &it:ans){
		std::cout<<it.first<<"  "<<it.second<<"\n";
	}
	return 0;
}