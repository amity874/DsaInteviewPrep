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
const int maxl = 1e7 + 1;
ll elimination1[maxl];
ll elimination2[maxl];
ll seive[maxl];
void Seive(){
	//here we will store max power of prime that divide the given factor of n
	for(int i=1;i<maxl;i++){
		seive[i]=i;
		elimination1[i]=maxl;	
	}
	for(int i=2;i<maxl;i++){
		if(seive[i]==i){
			for(int j=2*i;j<maxl;j+=i){
				seive[j]=i;
			}
		}
	}
}
int main(int argc, char const *argv[]) {
	file_i_o();
	Seive();
	ll n;
	std::cin>>n;
	ll res=1;
	for(int k=0;k<n;k++){
		ll x;
		std::cin>>x;
		std::unordered_map<ll,ll> mp;
		loop(i,1,x){
			ll factor;
			std::cin>>factor;
			while(factor>1){
				mp[seive[factor]]++;
				factor/=seive[factor];
			}
		}
		for(auto it=mp.begin();it!=mp.end();it++){
           elimination2[(*it).first]++;//this will store common factor index
           elimination1[(*it).first]=std::min(elimination1[(*it).first],(*it).second);
        }
	}
	for(ll i=2;i<maxl;i++){
        if(elimination2[i]==n){
            while(elimination1[i]--){
                res*=i;
                res%=mod;
            }
        }
    }
	cout<<res<<"\n";
	// logarr(seive,1,36);
	return 0;
}