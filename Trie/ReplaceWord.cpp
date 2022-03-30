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
struct Node{
	Node *link[26];
	bool Isterminal=false;
	bool containsKey(char ch){
		return link[ch-'a']!=NULL;
	}
	Node * get(char ch){
		return link[ch-'a'];
	}
	void put(char ch,Node *root){
		link[ch-'a']=root;
	}
	bool isEnd(){
		return this->Isterminal;
	}
	void setEnd(){
		this->Isterminal=true;
	}
};
class Trie{
private:
	Node *root;
public:
	Trie(){
		root=new Node();
	}
	void insert(std::string &str){
		Node *temp=root;
		int n=str.size();
		for(int i=0;i<n;i++){
			char ch=str[i];
			if(!temp->containsKey(ch)){
				temp->put(ch,new Node());
			}
			temp=temp->get(ch);
		}
		temp->setEnd();
	}
	std::string prefix(std::string &word){
		Node *temp=root;
		int n=word.size();
		std::string ans;
		for(int i=0;i<n;i++){
			char ch=word[i];
			if(!temp->containsKey(ch)){
				break;
			}
			else{
			ans.push_back(ch);
			temp=temp->get(ch);
			if(temp->isEnd()){
				return ans;
			}
		}
	}
	return word;
	}
};
string replaceWords(vector<string>& dictionary, string sentence) {
	Trie tr;
	for(auto &str:dictionary){
		tr.insert(str);
	}
	std::string ans="";
	std::string pre;
	int n=sentence.size();
	for(int i=0;i<n;i++){
		if(sentence[i]==' '){
			ans+=tr.prefix(pre);
			pre="";
			ans+=" ";
		}
		else{
			pre+=sentence[i];
		}
	}
	ans+=tr.prefix(pre);
	return ans;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}