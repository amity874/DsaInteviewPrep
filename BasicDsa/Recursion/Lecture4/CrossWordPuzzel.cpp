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
#define vc              vector<vector<char>>
// #define vc              vector<vector<bool>>
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
void print(vc &arr) {
    for(int i = 0 ;i<arr.size();i++) {
      for(int j = 0 ; j <arr.size(); j++) {
        std::cout<<arr[i][j]<<" ";
      }
      std::cout<<"\n";
    }
}
bool canplaceWordHorizontally(vc &arr,int i,int j,string &s){
	if(j-1>=0 && arr[i][j-1]!='+'){
		return false;
	}
	else if(j+ s.size()<arr[0].size() && arr[i][j+s.size()]!='+'){
		return false;
	}
	for(int jj=0;jj<s.size();jj++){
		if(j+jj>=arr[0].size()){
			return false;
		}
		if(arr[i][j+jj]=='-' or arr[i][j+jj]==s[jj]){
			continue;
		}
		else{
			return false;
		}
	}
	return true;
}
bool canplaceWordVertically(vc &arr,int i,int j,string &s){
	if(i-1>=0 && arr[i-1][j]!='+'){
		return false;
	}
	else if(i+s.size()<arr.size() && arr[i+s.size()][j]!='+'){
		return false;
	}
	for(int jj=0;jj<s.size();jj++){
		if(i+jj>=arr.size()){
			return false;
		}
		if(arr[i+jj][j]=='-' or arr[i+jj][j]==s[jj]){
			continue;
		}
		else{
			return false;
		}
	}
	return true;
}
std::vector<bool>placewordHorizontally(vc &arr,int i,int j,string &s){
	std::vector<bool>placed(s.size(),false);
	for(int jj=0;jj<s.size();jj++){
		if(arr[i][j+jj]=='-'){
		arr[i][j+jj]=s[jj];
		placed[jj]=true;
	}
}
	return placed;
}
std::vector<bool>placewordVertically(vc &arr,int i,int j,string &s){
	std::vector<bool>placed(s.size(),false);
	for(int ii=0;ii<s.size();ii++){
		if(arr[i+ii][j]=='-'){
		arr[i+ii][j]=s[ii];
		placed[ii]=true;
	}
}
	return placed;
}

void unplacewordHorizontally(vc &arr,std::vector<bool>&placed,int i,int j){
	for(int jj=0;jj<placed.size();jj++){
		if(placed[jj]==true){
			arr[i][j+jj]='-';
		}
	}
}
void unplacewordVertically(vc &arr,std::vector<bool>&placed,int i,int j){
	for(int ii=0;ii<placed.size();ii++){
		if(placed[ii]==true){
			arr[i+ii][j]='-';
		}
	}
}
void solution(vc &arr,std::vector<string>&words,int idx){
    if(idx==words.size()){
        print(arr);
        return;
    }
	int n=arr.size();
	int m=arr.size();
	string s=words[idx];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]=='-' && arr[i][j]==s[0]){
				if(canplaceWordHorizontally(arr,i,j,s)){
					std::vector<bool> placed=placewordHorizontally(arr,i,j,s);
					solution(arr,words,idx+1);
					unplacewordHorizontally(arr,placed,i,j);
				}
				if(canplaceWordVertically(arr,i,j,s)){
					std::vector<bool> placed =placewordVertically(arr,i,j,s);
					solution(arr,words,idx+1);
					unplacewordVertically(arr,placed,i,j);
				}
			}
		}
	}
}
int main(int argc, char const *argv[]) {
	// file_i_o();
  int n;
  std::vector<std::vector<char>> arr(10,std::vector<char>(10));
  loop(i,0,9){
  	loop(j,0,9){
  		std::cin>>arr[i][j];
  	}
  }
    std::cin>>n;
    std::vector<string>words(n);
    for (int i = 0 ; i <n; i++) {
     std::cin>>words[i];
    }
    solution(arr, words, 0);
	return 0;
}