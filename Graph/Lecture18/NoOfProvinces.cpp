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
int Get(std::vector<int>&parent,int a){
         return parent[a]=((parent[a]==a)?a:Get(parent,parent[a]));
}
void Union(std::vector<int>&parent,std::vector<int>&rank,int x,int y){
	int a=Get(parent,x);
	int b=Get(parent,y);
	if(rank[a]==rank[b]){
		rank[a]++;
	}
	else if(rank[a]>rank[b]){
		parent[b]=a;
	}
	else if(rank[b]>rank[a]){
		parent[a]=b;
	}
}
int findCircleNum(vector<vector<int>>& isConnected) {
	int n=isConnected.size(); 
	int m=isConnected[0].size(); 
    std::vector<int> parent(n);
    for(int i=0;i<n;i++){
    	parent[i]=i;
    }
    std::vector<int>rank(n,1);
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(isConnected[i][j]==1){
    			Union(parent,rank,i,j);
    		}
    	}
    }
    int cnt=0;
    for(int i=0;i<n;i++){
    	if(parent[i]==i){
    		cnt++;
    	}
    }
    return cnt;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}