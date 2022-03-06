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
int kadane(std::vector<int> &arr){
	int sum=0;
	int max_sum=INT_MIN;
	int n=arr.size();
	for(int i=0;i<n;i++){
		sum+=arr[i];
		if(sum<0){
			sum=0;
		}
		else if(sum>max_sum){
			max_sum=sum;
		}
	}
	if(max_sum<0){
		return max_sum;
	}
	for(int i=0;i<n;i++){
		if(max_sum<arr[i]){
			max_sum=arr[i];
		}
	}
	return max_sum;
}
int maxSumSubmatrix(vector<vector<int>>& arr,int k){
 int n=arr.size();
 int m=arr[0].size();
 int result=INT_MIN;
 int tlc,tlr,blc,brr;
 int start,end;
 std::vector<int> dp(n);
 for(int leftcol=0;leftcol<m;leftcol++){
 	dp.assign(n,0);
 	for(int rightcol=leftcol;rightcol<m;rightcol++){
 		for(int i=0;i<n;i++){
 			dp[i]+=arr[i][rightcol];
 		}
 		// logarr(dp,0,n-1);
 		// std::cout<<"\n";
 		int sum=kadane(dp);
 		// log(sum);
 		// if(sum<=k){
 		result=std::max(result,sum);
 		log(result);

 		// }
 	}
 }
 return result;  
 }

int main(int argc, char const *argv[]) {
	file_i_o();
	 ll n,m,k;
    cin>>n>>m>>k;
    std::vector<std::vector<int>>arr (n,std::vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<maxSumSubmatrix(arr,k);
	return 0;
}