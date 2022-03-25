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
std::unordered_map<std::string,int> Rank;
std::unordered_map<std::string,std::string> parent;
std::string Get(std::string &str){
if(!parent.count(str)){
	parent[str]=str;
	Rank[str]=1;
}
if(parent.count(str)){
	return str;
}
std::string ans=Get(parent[str]);
parent[str]=ans;
return ans;
}
void Union(std::string &s1,std::string &s2){
	s1=Get(s1);
	s2=Get(s2);
	if(Rank[s1]==Rank[s2]){
		Rank[s1]++;
	}
	if(Rank[s1]>Rank[s2]){
		parent[s2]=s1;
	}
	else if(Rank[s1]>Rank[s2]){
		parent[s1]=s2;
	}
}
bool find_Similiraty(vector<string> &s1,vector<string> &s2,std::vector<std::pair<std::string,std::string>> &Pair){
int n=s1.size();
int m=s2.size();
if(n!=m){
	return false;
}	
for(auto &it:Pair){
	Union(it.first,it.second);
}
for(int i=0;i<s1.size();i++){
	std::string w1=s1[i];
	std::string w2=s2[i];
	if(w1!=w2 && Get(w1)!=Get(w2)){
		return false;
	}
}
return true;
}
int main(int argc, char const *argv[]) {
	// file_i_o();
	int n;
	std::cin>>n;
	std::vector<std::string> sentence1(n);
	std::vector<std::string> sentence2(n);
	for(int i=0;i<n;i++){
		std::cin>>sentence1[i];
	}
	for(int i=0;i<n;i++){
		std::cin>>sentence2[i];
	}
	std::vector<std::pair<std::string,std::string>> Pair;
	int m;
	std::cin>>m;
	for(int i=0;i<m;i++){
		std::cin>>Pair[i].first>>Pair[i].second;
	}
	std::cout<<find_Similiraty(sentence1,sentence2,Pair);
	return 0;
}