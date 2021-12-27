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
int dp[205][205];
int xdir{0,0,-1,1};
int ydir{-1,1,0,0};
int dfs(int i,int j,int n,int m,vector<vector<int>>& matrix){
	int ans=0;
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	for(int d=0;d<4;d++){
		int x=xdir[d]+i;
		int y=ydir[d]+j;
		if(i>=0 and j>=0 and i<n and j<m and matrix[x][y]>matrix[i][j]){
			ans+=1+std::max(ans,x,y,n,m,matrix);
		}
	}
	dp[i][j]=ans;
	return ans;
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
	memset(dp,-1,sizeof(dp));
	int n=matrix.size();
	int m=matrix[0].size();
	int ans=INT_MIN;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans=std::max(ans,dfs(i,j,n,m,matrix));
		}
	}
	return ans;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}