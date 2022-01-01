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
void solution(std::string &s,std::string &pattern,std::unordered_map<char,string> &mp,std::string &op){
	if(pattern.size()==0){
		if(s.size()==0){
			std::unordered_set<char>mp1;
			for(char ch:op){
				if(!mp1.count(ch)){
					std::cout<<ch<<" -> "<<mp[ch]<<", ";
					mp1.insert(ch);
				}
			}
			std::cout<<"."<<"\n";
		}
		return;
	}
	char ch=pattern[0];
	std::string Pros=pattern.substr(1);
	if(mp.count(ch)){
		std::string p_mapping=mp[ch];
		if(s.size()>=p_mapping.size()){
			std::string left=s.substr(0,p_mapping.size());
			std::string right=s.substr(p_mapping.size());
			if(p_mapping==left){
				solution(right,Pros,mp,op);
			}
		}
	}
	else{
		for(int i=0;i<s.size();i++){
			std::string left=s.substr(0,i+1);
			std::string right=s.substr(i+1);
			mp[ch]=left;
			solution(right,Pros,mp,op);
			mp.erase(ch);
		}
	}
}
int main(int argc, char const *argv[]) {
	// file_i_o();
		std::string s,pattern;
		std::cin>>s>>pattern;
		std::unordered_map<char,string> mp;
		solution(s,pattern,mp,pattern);
	return 0;
}