/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>

BinaryTreeNode<int>* findSrc(BinaryTreeNode<int>* root,std::map< BinaryTreeNode<int>*,BinaryTreeNode<int>* > &mp,int start){
	BinaryTreeNode<int>* src;
	std::queue<BinaryTreeNode<int>*> qu;
	qu.push(root);
	while(not qu.empty()){
		BinaryTreeNode<int>* tp=qu.front();
		qu.pop();
		if(tp->data==start){
			src=tp;
		}
		if(tp->left){
			mp[tp->left]=tp;
			qu.push(tp->left);
		}
		if(tp->right){
			mp[tp->right]=tp;
			qu.push(tp->right);
		}
	}
	return src;
}
int bfs(BinaryTreeNode<int>* src,std::map<BinaryTreeNode<int>* ,BinaryTreeNode<int>*> &mp){
	std::queue<BinaryTreeNode<int>*> qu;
	std::map<BinaryTreeNode<int>*,int> vis;
	qu.push(src);
	vis[src]=1;
	int lvl=0;
	while(not qu.empty()){
		int n=qu.size();
		int f1=false;//for checking we are burning any node or not
		while(n--){
			auto node=qu.front();
			qu.pop();
			if(node->left && (not vis[node->left])){
				f1=true;
				vis[node->left]=true;
				qu.push(node->left);
			}
			if(node->right && (not vis[node->right])){
				f1=true;
				vis[node->right]=true;
				qu.push(node->right);
			}
			if(mp[node] && (not vis[mp[node]])){
				f1=true;
				vis[mp[node]]=true;
				qu.push(mp[node]);
			}
		}
		if(f1){
				lvl++;
			
		}
	}
	return lvl;
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
	std::map<BinaryTreeNode<int>* ,BinaryTreeNode<int>*> mp;
	BinaryTreeNode<int>* src=findSrc(root,mp,start);
	int min_time=bfs(src,mp);
	return min_time;
	}
