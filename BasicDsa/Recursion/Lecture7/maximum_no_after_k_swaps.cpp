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
std::string Max="0";
std::string Swap(std::string&s1,int i,int j){
	std::string left=s1.substr(0,i+1);
	std::string middle=s1.substr(i+1,j);
	std::string right=s1.substr(j+1);
	return left+std::to_string(j)+middle+std::to_string(i)+right;
}
void findMaximum(std::string &str,int k){
	if(k==0){
		if(std::stoi(str)>std::stoi(Max)){
			Max=str;
		}
		return;
	}
	for(int i=0;i<str.size()-1;i++){
		for(int j=i+1;j<str.size();j++){
			if(str[i]<str[j]){
				std::string swapped=Swap(str,i,j);
				findMaximum(swapped,k--);
			}
		}
	}
}
int main(int argc, char const *argv[]) {
	// file_i_o();
		std::string s1;
		std::cin>>s1;
		int k;
		std::cin>>k;
		Max = s1;
		findMaximum(s1, k);
		std::cout<<Max<<"\n";
	return 0;
}