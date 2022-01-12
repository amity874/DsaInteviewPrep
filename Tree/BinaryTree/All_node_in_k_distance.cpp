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
	int data=-1;
	Node*left=NULL;
	Node*right=NULL;
	Node(int data){
		this->data=data;
	}
};
std::vector<int> path;
Node* BuildBinaryTree(){
	int d;
	std::cin>>d;
	if(d==-1){
		return NULL;
	}
	Node* root=new Node(d);
	root->left=BuildBinaryTree();
	root->right=BuildBinaryTree();
	return root;
}
bool node_to_root_path(Node *root,int k){
	if(root==NULL){
		return false;
	}
	if(root->data==k){
		path.push_back(root->data);
		return true;
	}
	bool left=node_to_root_path(root->left,k);
	if(left){
		path.push_back(root->data);
		return true;
	}
	bool right=node_to_root_path(root->right,k);
	if(right){
		path.push_back(root->data);
		return true;
	}
	return false;
}
void Print_k_level_down(Node *root,int k,Node* bolcker){
	if(root==NULL or k<0 or root==bolcker){
		return;
	}
	if(root->data==k){
		std::cout<<root->data;
	}
	Print_k_level_down(root->left,k-1,bolcker);
	Print_k_level_down(root->right,k-1,bolcker);
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
	node_to_root_path(root,target->data);
	for(int i=0;i<path.size();i++){
		Print_k_level_down(root,k,(i==0)?NULL:path[i-1]);
	}
	return path;
}
std::vector<int>g[105];
std::vector<int>res;
void GenerateGraph(TreeNode* root){
	if(root==NULL){
		return;
	}
	if(root->left){
		g[root->data].push_back(root->left->data);
		g[root->left->data].push_back(root->data);
	}
	if(root->right){
		g[root->data].push_back(root->right->data);
		g[root->right->data].push_back(root->data);
	}
	GenerateGraph(root->left);
	GenerateGraph(root->right);
}
void dfs(int src,int k,std::vector<int>&visited){
	if(visited[src]){
		return;
	}
	visited[src]=true;
	if(k==0){
		res.push_back(src);
	}
	for(auto el:g[src]){
		dfs(el,k-1,visited);
	}
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
	std::vector<bool>visited(505,false);
	dfs(target->data,k,visited);
	return res;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	Node *n=BuildBinaryTree();
	bool res=node_to_root_path(n,6);
	for(auto &it:path){
		std::cout<<it<<" ";
	}
	std::cout<<"\n";
	std::cout<<res;
	return 0;
}