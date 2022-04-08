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
int shortestPath(vector<vector<int>>& grid, int k) {
	int xdir[4]={1,-1,0,0};
	int ydir[4]={0,0,-1,1};
	int n=grid.size();
	int m=grid[0].size();
	bool visited[n][m][k+1];
	queue<vector<int>> qu;
	int cnt=0;
	qu.push({0,0,k});
	while(not qu.empty()){
		int n=qu.size();
		while(n--){
		auto tp=qu.front();
		int x=tp[0];
		int y=tp[1];
		int wt=tp[2];
		visited[x][y][wt]=true;
		if(x== n-1 && y==n-1){
			return cnt;
		}
		for(int i=0;i<4;i++){
			int x1=xdir[i]+x;
			int y1=xdir[i]+y;
			if(x1<n and y1 <m and x1>=0 and y1>=0){
				if(not visited[x1][y1][wt] && grid[x1][y1]==0){
					qu.push({x1,y1,wt});
					visited[x1][y1][wt]=true;
				}
				else if(grid[x1][y1]==1 &&  wt>0 && !visited[x1][y1][wt-1]){
					qu.push({x1,y1,wt-1});
					visited[x1][y1][wt-1]=true;
				}
			}
		}
	}
	cnt++;
}
return -1;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}