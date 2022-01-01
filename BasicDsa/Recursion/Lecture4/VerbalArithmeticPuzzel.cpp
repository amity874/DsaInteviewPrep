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
int getnum(std::unordered_map<char,int>&charIntMap,std::string &s){
	string ans="";
for(int i=0;i<s.size();i++){
         ans+=std::to_string(charIntMap[s[i]]);   
}
	return std::stoi(ans);
}
void solution(std::string &unique,int idx,std::unordered_map<char,int>&charIntMap,std::vector<bool>&usedNumber,std::string&s1,std::string&s2,std::string &s3){
	if(idx==unique.size()){
		int num1=getnum(charIntMap,s1);
		int num2=getnum(charIntMap,s2);
		int num3=getnum(charIntMap,s3);
		if(num1+num2==num3){
			for(int i=0;i<26;i++){
				char ch= ('a' + i);
				if(charIntMap.count(ch)){
					std::cout<<ch<<"-"<<charIntMap[ch]<<" ";
				}
			}
			std::cout<<"\n";
		}
		return;
	}
	char uns=unique[idx];//uns==unique string
	for(int pos=0;pos<=9;pos++){
		if(usedNumber[pos]==false){
			charIntMap[uns]=pos;
			usedNumber[pos]=true;
			solution(unique,idx+1,charIntMap,usedNumber,s1,s2,s3);
			usedNumber[pos]=false;
			charIntMap[uns]=-1;
		}
	}
}
int main(int argc, char const *argv[]) {
	// file_i_o();
    string s1,s2,s3;
    std::cin>>s1>>s2>>s3;
    std::unordered_map<char,int> charIntMap;
    string unique = "";
   for (int i = 0; i < s1.length(); i++) {
      if (!charIntMap.count(s1[i])) {
        charIntMap[s1[i]]=-1;
        unique +=s1[i];
      }
    }
    for (int i = 0; i < s2.length(); i++) {
      if (!charIntMap.count(s2[i])) {
        charIntMap[s2[i]]=-1;
        unique +=s2[i];
      }
    }

    for (int i = 0; i < s3.length(); i++) {
      if (!charIntMap.count(s3[i])) {
        charIntMap[s3[i]]=-1;
        unique +=s3[i];
      }
    }

    std::vector<bool>usedNumber(10,false);
    solution(unique, 0, charIntMap, usedNumber, s1, s2, s3);
	return 0;
}