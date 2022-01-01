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
bool possible(std::vector<int>&v,int mid,int k){
	int count=0;
	for(int i=0;i<v.size();i++){
		count+=v[i]/mid;
	}
	return count<=k;
}
int minimize_maximum(std::vector<int>&v,int n,int k){
	std::vector<int>::iterator result = std::min_element(v.begin(), v.end());
    int lo=std::distance(v.begin(), result);
    result=std::max_element(v.begin(),v.end());
    int hi=std::distance(v.begin(),result);
    int ans=0;
    while(lo<=hi){
    	int mid=lo+(hi-lo)/2;
    	if(possible(v,mid,k)){
    		ans=mid;
    		hi=mid-1;
    	}
    	else{
    		lo=mid+1;
    	}
    }
    return ans;
}
int main(int argc, char const *argv[]) {
	// file_i_o();
	int n,k;
	std::cin>>n>>k;
	std::vector<int>arr(n);
	loop(i,0,n-1){
		std::cin>>arr[i];
	}
	std::cout<<minimize_maximum(arr,n,k);
	return 0;
}