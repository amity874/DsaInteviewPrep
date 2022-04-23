/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isleaf(TreeNode<int>* root) {
  return !root -> left && !root -> right;
}
void addLeftBoundary(TreeNode<int> *root,vector<int> &res){
	TreeNode<int> *curr=root->left;
	while(curr){
		if(!isleaf(curr)) res.push_back(curr->data);
		if(curr->left)curr=curr->left;
		else curr=curr->right;
	}
}
void addrightBoundary(TreeNode<int> *root,vector<int> &res){
	TreeNode<int> *curr=root->right;
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
void addLeafNode(TreeNode<int> *root ,vector<int> &res){
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
addLeftBoundary(root,res);
addLeafNode(root,res);
addrightBoundary(root,res);
return res;
}