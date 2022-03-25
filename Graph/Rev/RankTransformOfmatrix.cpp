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
#define pii             pair<int,int>
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
pii parent[505][505];
pii Get(pii a){
	return parent[a.first][a.second]=(parent[a.first][a.second]==a?a:Get(parent[a.first][a.second]));
}
void Union(pii a,pii b){
	a=Get(a);
	b=Get(b);
	parent[a.first][a.second]=b;
}
vector<vector<int>> matrixRankTransform(vector<vector<int>>& arr){
	int n=arr.size();
	int m=arr[0].size();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			parent[i][j]={i,j};
		}
	}
	std::vector<std::vector<int>> ans(n,std::vector<int>(m));
	//initially connecting the identical element because all these are in same component
	for(int i=0;i<n;i++){
		std::unordered_map<int,std::pair<int,int>> mp;
		for(int j=0;j<m;j++){
			if(mp.count(arr[i][j])){
				Union(mp[arr[i][j]],{i,j});
			}
			mp[arr[i][j]]={i,j};
		}
	}
	for(int j=0;j<m;j++){
		std::unordered_map<int,std::pair<int,int>> mp;
		for(int i=0;i<n;i++){
			if(mp.count(arr[i][j])){
				Union(mp[arr[i][j]],{i,j});
			}
			mp[arr[i][j]]={i,j};
		}
	}
	std::vector<pair<int,int>> g[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			pii x=Get({i,j});
			g[x.first][x.second].push_back({i,j});
		}
	}
	std::map<int,std::vector<std::vector<pair<int,int>>>> mp;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j].size()){
				mp[arr[i][j]].push_back({g[i][j]});
			}
		}
	}
	vector<int> row(n);
	vector<int> col(m);
	for(auto &i:mp){
		for(auto &j:i.second){
			int res=0;
			for(auto &k:j){
				int x=k.first;
				int y=k.second;
				res=std::max(res,1+max(row[x],col[y]));
			}
			for(auto &k:j){
				int x=k.first;
				int y=k.second;
				ans[x][y]=res;
				row[x]=std::max(row[x],res);
				col[y]=std::max(col[y],res);
			}
		}
	}
	return ans;
}
int main(int argc, char const *argv[]) {
	// file_i_o();

	return 0;
}