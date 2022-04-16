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
string minWindow(string s, string t) {
int i=-1;
int j=-1;
std::unordered_map<char,int> mp1;
for(int i=0;i<t.size();i++){
	mp1[t[i]]++;
}
int cnt=mp1.size();
int mcnt=0;
std::unordered_map<char,int> mp2;  
std::string o_ans;   
bool f1=false;
bool f2=false;   
while(true){
	while(i<s.size()-1 && mcnt<cnt){
		i++;
		char ch=s[i];
		mp2[ch]++;
		if(mp2[ch]<=mp1[ch]){
			mcnt++;
		}
		f1=true;
	}
	while(j<i && mcnt==cnt){
		std::string temp=s.substr(j+1,i+1);
		if(o_ans.size()==0 || temp.size()<o_ans.size()){
			o_ans=temp;
		}
		j++;
		char ch=s[j];
		if(mp2[ch]==1){
			mp2.erase(ch);
		}
		else{
			mp2[ch]--;
		}
		if(mp1[ch]<mp2[ch]){
			mcnt--;
		}
		f2=true;
	}
	if(f1==false && f2==false){
		break;
	}
}
return o_ans;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}