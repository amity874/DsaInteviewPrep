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
std::string alienOrder(std::vector<std::string>& words) {
	std::unordered_map<char,std::set<char>> g;
	std::unordered_map<char,int> indegree;
	for(int i=0;i<words.size();i++){
		for(int j=0;j<words[i].size();j++){
			indegree[words[i][j]]=true;
		}
	}
	for(int i=0;i<words.size()-1;i++){
		std::string curr=words[i];
		std::string next=words[i+1];
		int cmp=std::min(curr.size(),next.size());
		for(int j=0;j<cmp;j++){
			if(curr[j]!=next[j]){
				std::set<char>adj=g[curr[j]];
				if(adj.count(next[j])==0){
					g[curr[j]].insert(next[j]);
					indegree[j]++;
				}
				break;
			}
			if(j==cmp-1 && curr.size()>next.size()){
				return "";
			}
		}
	}
	std::queue<char> qu;
	for(auto &it:indegree){
		if(it.second==0){
			qu.push(it.first);
		}
	}
	std::string res="";
	while(not qu.empty()){
		char top=qu.front();
		qu.pop();
		res+=top;
		for(auto &child:g[top]){
			indegree[child]--;
			if(indegree[child]--){
				qu.push(child);
			}
		}
	}
	return res;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}