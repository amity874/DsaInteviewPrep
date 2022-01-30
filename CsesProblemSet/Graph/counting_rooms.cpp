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
void dfs_helper(std::vector<std::vector<bool>>&arr,int i,int j,int n,int m){
	if(i>=n or j>=m or i<0 or j<0){
	   return;
	}
	if(arr[i][j]==0){
		return;
	}
	arr[i][j]=0;
	dfs_helper(arr,i+1,j,n,m);
	dfs_helper(arr,i,j+1,n,m);
	dfs_helper(arr,i-1,j,n,m);
	dfs_helper(arr,i,j-1,n,m);
	return;
}
ll dfs(std::vector<std::vector<bool>>&arr){
	ll n=arr.size();
	ll m=arr[0].size();
	ll cc=0;
	std::vector<std::vector<bool>>visited(n,std::vector<bool>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==1){
				dfs_helper(arr,i,j,n,m);
				cc++;
			}
		}
	}
	return cc;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	ll n,m;
	std::cin>>n>>m;
	std::vector<std::vector<bool>> arr(n,std::vector<bool>(m));
	loop(i,0,n-1){
		loop(j,0,m-1){
			char ch;
			std::cin>>ch;
			if(ch=='#'){
				arr[i][j]=0;
			}else{
				arr[i][j]=1;
			}
		}
	}
	// loop(i,0,n-1){
	// 	loop(j,0,m-1){
	// 		std::cout<<arr[i][j];
	// 	}
	// 	std::cout<<"\n";
	// }
	std::cout<<dfs(arr);
	return 0;
}