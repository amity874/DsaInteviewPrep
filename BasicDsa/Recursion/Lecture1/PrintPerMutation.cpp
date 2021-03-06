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
void solution(int idx,int nlenght,std::unordered_map<char,int>&chmap,char oddchar,std::string osf){
	if(idx>nlenght){
		std::string rev="";
		for(int i=osf.size()-1;i>=0;i--){
			rev+=osf[i];
		}
		if(oddchar!=NULL){
			osf+=oddchar;
		}
		osf+=rev;
		std::cout<<osf<<"\n";
		return;
	}
	for(auto&ch:chmap){
		int freq=ch.second;
		if(freq>0){
			ch.second=freq-1;
			solution(idx+1,nlenght,chmap,oddchar,osf+ch.first);
			ch.second=freq;
		}
	}
}
int main(int argc, char const *argv[]) {
	std::string s;
	std::cin>>s;
	std::unordered_map<char,int> chmap;
	for(int i=0;i<s.size();i++){
		char ch=s[i];
		if(!chmap.count(ch)){
			chmap[ch]=1;
		}
		else{
			chmap[ch]++;
		}
	}
	int odd=0;
	char oddchar;
	int nlenght=0;
	for(int i=0;i<s.size();i++){
		int x=chmap[s[i]];
		if(x%2!=0){
			oddchar=chmap[s[i]];
			odd++;
		}
		chmap[s[i]]=chmap[s[i]]/2;
		nlenght+=chmap[s[i]]/2;
	}
	solution(0,nlenght,oddchar,chmap,"");
	return 0;
}