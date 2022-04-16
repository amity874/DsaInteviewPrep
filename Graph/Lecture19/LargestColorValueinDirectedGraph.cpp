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
int findMax(vector<int> &dp,int src,int c,vector<vector<int>> &g,std::string &colors){
if(dp[src]!=-1){
	return dp[src];
}
dp[src]=0;
for(auto &it:g[src]){
	dp[src]=max(dp[src],findMax(dp,it,c,g,colors));
}
dp[src]+=(colors[src]==(c+'a'));
return dp[src];
}
int largestPathValue(string colors, vector<vector<int>>& edges) {
int n=colors.size();
vector<int> indegre(n,0);
vector<int> dp(n);
vector<vector<int>> g(n);
for(auto &it:edges){
g[it[0]].push_back(it[1]);
indegre[it[1]]++;
}
std::queue<int> qu;
int cnt=0;
for(int i=0;i<n;i++){
	if(indegre[i]==0){
		qu.push(i);
        cnt++;
	}
}
while(not qu.empty()){
	int top=qu.front();
	qu.pop();
	for(auto &it:g[top]){
		indegre[it]--;
		if(indegre[it]==0){
			qu.push(it);
			cnt++;
		}
	}
}
int res=INT_MIN;
if(cnt<n){
	return -1;
}
else{
	for(int c=0;c<=25;c++){
		for(int i=0;i<n;i++){
            dp[i]=-1;
        }
		for(int i=0;i<n;i++){
		res=std::max(res,findMax(dp,i,c,g,colors));
	}
	}
}
return res;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}