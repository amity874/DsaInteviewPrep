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

 // * Definition for a binary tree node.
 struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string str="";
        if(root==NULL){
        	return str;
        }
        std::queue<TreeNode *> qu;
        qu.push(root);
        while(not qu.empty()){
        	TreeNode * node=qu.front();
        	qu.pop();
        	if(node==NULL){
        		str.append("#,");
        	}
        	else{
        		str.append(std::to_string(node->val));
        	}
        	if(node!=NULL){
        		qu.push(root->left);
        		qu.push(root->right);
        	}
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	if(data.size()==0){
    		return NULL;
    	}
    	std::queue<TreeNode*> qu;
    	stringstream str(data);
    	string s;
    	getline(str,s,',');
    	TreeNode * root=new TreeNode(stoi(s));
    	qu.push(root);
    	while(not qu.empty()){
    		TreeNode * node=qu.front();
    		qu.pop();
    		getline(str,s,',');
    		if(s=="#"){
    			node->left=NULL;
    		}
    		else{
    			TreeNode *curr=new TreeNode(stoi(s));
    			qu.push(curr);
    			node->left=curr;
    		}
    		getline(str,s,',');
    		if(s=="#"){
    			node->right=NULL;
    		}
    		else{
    			TreeNode *curr=new TreeNode(stoi(s));
    			qu.push(curr);
    			node->right=curr;
    		}
    	}
    	return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main(int argc, char const *argv[]) {
	file_i_o();
	return 0;
}