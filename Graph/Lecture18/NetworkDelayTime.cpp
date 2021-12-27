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

void modifiedBfs(vector<vector<int>>& times,int n,int src,vector<vector<int>>& dist){
	dist[src]=0;
	std::queue<std::pair<int,int>>qu;
	qu.push({src,dist[src]});
	while(not qu.empty()){
		int tp=qu.front().first;
		int wt=qu.front().second;
		qu.pop();
		for(auto &it:g[tp]){
			if(dist[it.first]>dist[tp]+it.second){
				qu.push({it.first,wt+it.second});
				dist[it.second]=wt+it.second;
			}
		}
	}
}
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
	std::vector<std::list<std::pair<int,int>>> g;
	std::vector<int>dist(n+1,INT_MAX);
	for(int i=0;i<n;i++){
		int u=times[i][0];
		int v=times[i][1];
		int wt=times[i][2];
		g[u].push_back({v,wt});
	}
	modifiedBfs(times,n,k,dist);
	int time=0;
	for(int i=1;i<=n;i++){
		if(dist[i]==INT_MAX){
			return -1;
		}
		time=std::min(time,dist[i]);
	}
	return time;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}