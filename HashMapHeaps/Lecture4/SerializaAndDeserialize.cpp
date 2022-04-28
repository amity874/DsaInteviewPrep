/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
        		str.append(std::to_string(node->val)+",");
        	}
        	if(node!=NULL){
        		qu.push(node->left);
        		qu.push(node->right);
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
        cout<<data;
    	return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));