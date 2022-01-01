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
void travel(std::vector<std::vector<int>> &arr,std::vector<std::vector<bool>> &visited,std::vector<int>&bag,int n,int m,int i,int j){
	if(i<0 or j<0 or i>=n or j>=m or visited[i][j],arr[i][j]==0){
		return;
	}
	visited[i][j]=true;
	bag.push_back(arr[i][j]);
	travel(arr,visited,bag,n,m,i-1,j);
	travel(arr,visited,bag,n,m,i,j+1);
	travel(arr,visited,bag,n,m,i-1,j-1);
	travel(arr,visited,bag,n,m,i+1,j);
}
int goldMine(std::vector<std::vector<int>> &arr,int n,int m){
int ans=0;
std::vector<std::vector<bool>> visited(n,std::vector<bool>(m));
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		if(arr[i][j]!=0){
			std::vector<int>bag;
			travel(arr,visited,bag,n,m,i,j);
		}
		int new_ans=0;
		for(int i=0;i<bag.size();i++){
			new_ans+=bag[i];
		}
		if(ans<new_ans){
			ans=new_ans;
		}
	}
}
return ans;
}
int main(int argc, char const *argv[]) {
	// file_i_o();
		int n,m;
		std::cin>>n>>m;
		std::vector<std::vector<int>> arr(n,std::vector<int>(m));
		for(int i = 0; i < n; i++){
			for(int j = 0 ;j<m; j++){
				std::cin>>arr[i][j];
			}
		}
		goldMine(arr,n,m);
	return 0;
}