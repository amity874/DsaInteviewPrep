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
template <typename T>
struct TreeNode {
  int data;
  struct TreeNode * left, * right;
};

bool isLeaf(TreeNode * root) {
  return !root -> left && !root -> right;
}
bool isleaf(TreeNode *root){
	return !(root->left && !root->right);
}
void addLeftBoundary(TreeNode *root,vector<int> &res){
	TreeNode *curr=root->left;
	while(curr){
		if(!isleaf(curr)) res.push_back(curr->data);
		if(curr->left)curr=curr->left;
		else curr=curr->right;
	}
}
void addrightBoundary(TreeNode *root,vector<int> &res){
	TreeNode *curr=root->right;
	vector<int> temp;
	while(curr){
		if(!isleaf(curr))temp.push_back(curr->data);
		if(curr->right)curr=curr->right;
		else curr=curr->left;
	}
	for(int i=temp.size()-1;i>=0;i--){
		res.push_back(temp[i]);
	}
}
void addLeafNode(TreeNode *root ,vector<int> &res){
	if(isleaf(root)){
		res.push_back(root->data);
		return;
	}
	if(root->left){
		addLeafNode(root->left,res);
	}
	if(root->right){
		addLeafNode(root->right,res);
	}
}
vector<int> traverseBoundary(TreeNode<int>* root){
vector<int> res;
if(!root)return res;
if(!isleaf(root)){
	res.push_back(root->data);
}
addLeafNode(root,res);
addLeafNode(root,res);
addrightBoundary(root,res);
return res;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}