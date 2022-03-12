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
std::string Swap(std::string &str,int i,int j){
	std::string temp=str;
	temp[i]=str[j];
	temp[j]=str[i];
	return temp;
}
int slidingPuzzle(vector<vector<int>>& board) {
int n=board.size();
int m=board[0].size();
std::string target="123450";
std::string initial="";
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		initial+=to_string(board[i][j]);
	}
}  
    cout<<initial<<": ";
    cout<<target<<":";
if(initial==target){
	return 0;
}
   vector<vector<int>> direction={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};  
std::queue<std::string> qu;
qu.push(initial);
std::set<string> visited;
int lvl=0;
while(not qu.empty()){
	int n=qu.size();
	lvl++;
    // cout<<n<<" ";
    while(n--){
	std::string tp=qu.front();
	qu.pop();
	if(tp==target){
		return lvl;
	}
	int idx=-1;
	for(int i=0;i<tp.size();i++){
		if(tp[i]=='0'){
			idx=i;
            break;
		}
	}
	std::vector<int> dir=direction[idx];
        std::string temp;
	for(int i=0;i<dir.size();i++){
		std::string swapped=Swap(tp,idx,dir[i]);
		if(visited.count(swapped)){
			continue;
		}
		qu.push(swapped);
		visited.insert(swapped);
	}
}
}
return -1;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}