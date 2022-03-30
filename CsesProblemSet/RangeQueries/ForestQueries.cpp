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

int main(int argc, char const *argv[]) {
	file_i_o();
	int n,m;
	std::cin>>n>>m;
	int arr[n+1][n+1];
	int prefix[n+1][n+1];
	memset(prefix,0,sizeof(prefix));
	memset(arr,0,sizeof(arr));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char x;
			std::cin>>x;
			if(x=='*'){
				arr[i][j]=1;
			}
			else{
				arr[i][j]=0;
			}
			prefix[i][j]=arr[i][j]+prefix[i][j-1];//column wise sum
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			prefix[i][j]+=prefix[i-1][j];
		}
	}
	// loop(i,1,n){
	// 	loop(j,1,n){
	// 		std::cout<<prefix[i][j]<<" ";
	// 	}
	// 	std::cout<<"\n";
	// }
	while(m--){
		ll x1,y1,x2,y2;
		std::cin>>x1>>y1>>x2>>y2;
		std::cout<<(prefix[x2][y2]-
			prefix[x2][y1-1]-
			prefix[x1-1][y2]+
			prefix[x1-1][y1-1])<<"\n";
	}
	return 0;
}