#include<bits/stdc++.h>
// https://www.codechef.com/problems/DIGJUMP
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
vector<ll> g[100005];
ll bfs(ll src,ll n,std::string &s){
ll dist[100005];
// log(n);
vector<bool> visited(n,false);
std::queue<ll> qu;
qu.push(src);
dist[src]=0;
visited[src]=true;
while(not qu.empty()){
	int tp=qu.front();
        qu.pop();
        if(tp==n-1)break;
        int val=s[tp]-'0';
        int sz=g[val].size();
        for(int i=0;i<sz;i++){
            int idx=g[val][i];
            if(not visited[idx]){
                visited[idx]=true;
                qu.push(idx);
                dist[idx]=dist[tp]+1;
            }
        }
	 g[val].clear();
      if(tp-1>=0 && !visited[tp-1]){
            qu.push(tp-1);
            visited[tp-1]=true;
            dist[tp-1]=dist[tp]+1;
        }
        if(tp+1<n && !visited[tp+1]){
            qu.push(tp+1);
            visited[tp+1]=true;
            dist[tp+1]=dist[tp]+1;
        }
}
return dist[n-1];
}
int main(int argc, char const *argv[]) {
	file_i_o();
	std::string str;
	std::cin>>str;
	int n=str.size();
	for(int i=0;i<n;i++){
		g[str[i]-'0'].push_back(i);//here we are storing the index in our adj list
	}
	std::cout<<bfs(0,n,str);
	return 0;
}