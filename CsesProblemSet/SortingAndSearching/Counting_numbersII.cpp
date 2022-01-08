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

int main(int argc, char const *argv[]) {
	file_i_o();
	ll n,m;
	std::cin>>n>>m;
	std::vector<ll>arr(n);
	std::vector<ll>pos(n+1,INT_MAX);
	loop(i,0,n-1){
		std::cin>>arr[i];
		pos[arr[i]]=i;
	}
	ll count=0;
	loop(i,1,n){
		if(pos[i]<pos[i-1]){
			count++;
		}
	}
	while(m--){
		ll a,b;
		std::cin>>a>>b;
		a--;b--;
		std::set<std::pair<ll,ll>> effected_set;
		// find the element that will be effected
		if(arr[a]>0){
			effected_set.insert({arr[a]-1,arr[a]});
		}
		if(arr[a]<n){
			effected_set.insert({arr[a],arr[a]+1});
		}
		if(arr[b]>0){
			effected_set.insert({arr[b]-1,arr[b]});
		}
		if(arr[b]<n){
			effected_set.insert({arr[b],arr[b]+1});
		}
		// remove the contribution for effected element
		for(auto el:effected_set){
			if(pos[el.second]<pos[el.first]){
				count--;
			}
		}
		//swap the element;
		std::swap(arr[a],arr[b]);
		std::swap(pos[arr[a]],pos[arr[b]]);
		for(auto el:effected_set){
			if(pos[el.second]<pos[el.first]){
				count++;
			}
		}
		std::cout<<count<<"\n";
	}
	return 0;
}