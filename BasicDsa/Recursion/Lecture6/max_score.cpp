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
int solution(std::vector<std::string>&words,std::vector<int>&freq,std::vector<int>&score,int idx){
	if(idx==words.size()){
		return 0;
	}
	int ans1=solution(words,freq,score,idx+1);
	std::string temp=words[idx];
	bool flag=true;
	int sword=0;
	for(int i=0;i<temp.size();i++){
		char ch=temp[i];
		if(freq[ch-'0']==0){
			flag=false;
		}
		freq[ch-'0']--;
        sword+=score[ch-'a'];
	}
	int ans2=0;
	if(flag){
		ans2=solution(words,freq,score,idx+1)+sword;
	}
	for(int i=0;i<temp.size();i++){
		char ch=temp[i];
		freq[ch-'0']++;
	}
	return std::max(ans1,ans2);
}
int main(int argc, char const *argv[]) {
	// file_i_o();
		int nofWords;
		std::cin>>nofWords;
		std::vector<std::string>words(nofWords);
		for(int i = 0 ; i < words.size(); i++) {
			std::cin>>words[i];
		}
		int nofLetters;
		std::cin>>nofLetters;
		std::vector<char>latters(nofLetters);
		for (int i = 0; i < latters.size(); i++) {
			std::cin>>latters[i];
		}
		std::vector<int>score(26);
		for (int i = 0; i < score.size(); i++) {
			std::cin>>score[i];
		}
		// if (words==NULL || words.size() == 0 || letters == NULL || letters.size() == 0 || score == NULL
		// 		|| score.size() == 0) {
		// 	std::cout<<0;
		// 	return 0;
		// }
		std::vector<int>freq(26);
		for(auto ch:latters){
			freq[ch-'0']++;
		}
		std::cout<<solution(words, freq, score, 0);
	return 0;
}