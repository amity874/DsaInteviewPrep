class Solution {
public:
  vector<string> ans;
	struct Node {
    Node *links[26]; 
    bool isTerminal = false; 
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }
    Node* get(char ch) {
        return links[ch-'a']; 
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node; 
    }
    void setEnd() {
        isTerminal = true; 
    }
    bool isEnd() {
        return isTerminal; 
    }
}; 
void insert(std::string &str,Node *root){
	int n=str.size();
	Node *curr=root;
	for(int i=0;i<n;i++){
		char ch=str[i];
		if(not (curr->containsKey(ch))){
			curr->put(ch,new Node());
		}
		curr=curr->get(ch);
	}
	curr->isTerminal=true;
}
bool search(string &word,Node *root){
	int n=word.size();
	Node *curr=root;
	for(auto &ch:word){
		if(curr->containsKey(ch)){
			curr=curr->get(ch);
		}
		else{
			return false;
		}
	}
	return curr->isTerminal;
}
void dfs(std::string &s,int idx,Node *root,std::string ros){
	if(idx==s.size()){
		ans.push_back(ros.substr(0,ros.size()-1));
		return;
	}
	std::string str="";
	for(int pos=idx;pos<s.size();pos++){
		str.push_back(s[pos]);
		if(search(str,root)){
			dfs(s,pos+1,root,ros+str+" ");
		}
	}
}
vector<string> wordBreak(string s, vector<string>& wordDict) {
	int n=s.size();
	Node *curr=new Node();
	for(std::string str:wordDict){
		insert(str,curr);
	}
	dfs(s,0,curr,"");
	return ans;
}
};