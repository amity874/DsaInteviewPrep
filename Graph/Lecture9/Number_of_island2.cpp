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
  int Get(int a,std::vector<int> &parent){
	return parent[a]=(parent[a]==a?a:Get(parent[a],parent));
}
int xdir[4]={-1,1,0,0};
int ydir[4]={0,0,-1,1};
int main(int argc, char const *argv[]) {
	// file_i_o();
	int n,m,k;
	int cnt=0;
	std::cin>>n>>m>>k;
	vector<vector<int>> arr(k,vector<int>(2));
	vector<int> ans;
	loop(i,0,k-1){
		loop(j,0,1){
			std::cin>>arr[i][j];
		}
	}
	vector<int> par(n*m,-1);
	vector<int> rank(n*m,1);
	for(int i=0;i<arr.size();i++){
		int row=arr[i][0];
		int col=arr[i][1];
		int pos1=row*m+col;
		if(par[pos1]!=-1){
			ans.push_back(cnt);
			continue;
		}
		par[pos1]=pos1;
		cnt++;
		for(int i=0;i<4;i++){
			int x=row+xdir[i];
			int y=col+ydir[i];
			int pos2=x*m+y;
			if(x<0 or y<0 or x>=n or y>=m or par[pos2]==-1){
				continue;
			}
			int a=Get(pos1,par);
			int b=Get(pos2,par);
			if(a!=b){
				if(rank[a]==rank[b]){
					rank[a]++;
				}
				if(rank[a]>rank[b]){
					par[b]=a;
				}
				else{
					par[a]=b;
				}
				cnt--;
			}
		}
		ans.push_back(cnt);
	}
	loop(i,0,ans.size()-1){
		std::cout<<"["<<ans[i]<<",";
	}
	std::cout<<"]";
	return 0;
}