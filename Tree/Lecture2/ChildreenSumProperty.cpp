/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
	if(root==NULL){
		return;
	}
	int childSUm=0;
	if(root->left){
		childSUm+=root->left->data;
	}
	if(root->right){
		childSUm+=root->right->data;
	}
	if(root->data<childSUm){
		root->data=childSUm;
	}
	else{
		if(root->left){
			root->left->data=root->data;
		}
		if(root->right){
			root->right->data=root->data;
		}
	}
	changeTree(root->left);
	changeTree(root->right);
	int total=0;
	if(root->left){
		total+=root->left->data;
	}
	if(root->right){
		total+=root->right->data;
	}
	if(root->left or root->right){
		root->data=total;
	}
}  