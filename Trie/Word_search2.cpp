class Solution {
public:
struct Node{
	std::string str;
	bool isTerminal;
	char ch;
	std::unordered_map<char,Node*> childreen;
	Node(char ch){
		this->ch=ch;
		this->isTerminal=false;
	}
};
class Trie{
public:
	Node *root;
	Trie(){
		root=new Node('\0');
	}
	void insert(std::string &str){
		Node* temp=root;
		int n=str.size();
		for(int i=0;i<n;i++){
			char ch=str[i];
			if(temp->childreen.count(ch)){
				temp=temp->childreen[ch];
			}
			else{
				Node *n=new Node(ch);
				temp->childreen[ch]=n;
				temp=n;
			}
		}
		temp->isTerminal=true;
		temp->str=str;
	}
	void dfs(vector<vector<char>>& board,int i,int j,int n,int m,vector<string> &ans){
	char ch=board[i][j];
	 if(board[i][j]=='$' || root->childreen[ch]==NULL)  
            return;
	root=root->childreen[ch];
	if(root->isTerminal==true){
		ans.push_back(root->str);
		root->isTerminal=false;
	}
        char ch1=board[i][j];
	board[i][j]='$';
	if(i>0)
        dfs(board,i-1,j,n,m,ans);
    if(i<n-1)   //DOWN
            dfs(board,i+1,j,n,m,ans);
     if(j>0)     //LEFT
            dfs(board,i,j-1,n,m,ans);
    if(j<m-1)   //RIGHT
            dfs(board,i,j+1,n,m,ans);
        
	board[i][j]=ch1;
}
};
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {        
	vector<std::string> ans;
	Trie tr;
	int n=board.size();
	int m=board[0].size();
	for(auto &el:words){
		tr.insert(el);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			tr.dfs(board,i,j,n,m,ans);
		}
	}
	return ans;
}
};