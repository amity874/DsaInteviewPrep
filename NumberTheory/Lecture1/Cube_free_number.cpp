#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
// https://www.spoj.com/problems/CUBEFR/#:~:text=A%20cube%20free%20number%20is,are%20not%20cube%20free%20number.
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
#define MAX 1000005
std::bitset<MAX> isCube;
std::vector<ll> Cube;
std::unordered_map<ll,ll>mp1;
void cubeFree(){
	isCube.set();
	for(ll div=2;div*div*div<=MAX;div++){
		if(isCube[div]){
			for(ll mlt=1;mlt*div*div*div<=MAX;mlt++){
				isCube[mlt*div*div*div]=false;
			}
		}
	}
	ll c=1;
	mp1[1]=c;
	for(ll i=2;i<=MAX;i++){
		if(isCube[i]){
			mp1[i]=++c;
		}
	}
}
int main(int argc, char const *argv[]) {
	file_i_o();
	ll t;
	std::cin>>t;
	ll c=1;
	cubeFree();
	while(t--){
		ll n;
		std::cin>>n;
		if(mp1.count(n)){
           std::cout<<"Case "<<c++<<": "<<mp1[n]<<"\n";
       }
       else{
             std::cout<<"Case "<<c++<<": "<<"Not Cube Free "<<"\n";
       }
	}
	return 0;
}

