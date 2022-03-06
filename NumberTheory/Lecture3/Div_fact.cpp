#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
// https://www.spoj.com/problems/DIVFACT/
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
#define MAX 50005
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

std::bitset<MAX> isPrime;
std::vector<int>Prime;
void GeneratePrime() {
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2; i*i <= MAX; i++) {
        if(isPrime[i]) {
            for(ll j = i; j*i <= MAX; j++) {
                isPrime[j*i] = false;
            }
        }
    }
    Prime.push_back(2);
    for(int i = 3; i <= MAX; i+= 2) {
        if(isPrime[i]) Prime.push_back(i);
    }
}
void Seg_seive(ll a,ll b){
    std::vector<bool> res(b-1+1,true);
    if(b==1){
        a++;
    }
    for(int i=0;Prime[i]*Prime[i]<=b;i++){
        ll j=(a/Prime[i])*Prime[i];
        if(j<a){
            j+=Prime[i];
        }
        for(;j<=b;j++){
            if(j!=Prime[i]){
                res[j-a]=false;
            }
        }
    }
    for(int i=a;i<=b;i++){
        if(i==2 or res[i-a]){
            std::cout<<i<<"\n";
        }
    }
}
ll divFact(ll n){
	ll result=1;
	for(int i=0;Prime[i]<=n;i++){
		ll count=0;
		ll p=Prime[i];
		while((n/p)!=0){
			count=(count+(n/p))%mod;
			p=p*Prime[i];
		}
		result=(result*(count+1)%mod)%mod;
	}
	return result;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	GeneratePrime();
	ll t;
	std::cin>>t;
	while(t--){
		ll n;
		std::cin>>n;
		std::cout<<divFact(n)<<"\n";
	}
	return 0;
}