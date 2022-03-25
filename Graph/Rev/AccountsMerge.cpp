class Solution {
public:
 int Get(vector<int> &parent,int a){
    return parent[a]=((parent[a]==a)?a:Get(parent,parent[a]));
}
void Union(vector<int> &parent,vector<int> &rank,int a,int b){
    a=Get(parent,a);
    b=Get(parent,b);
    if(rank[a]==rank[b]){
        rank[a]++;
    }
    if(rank[a]>rank[b]){
        parent[b]=a;
    }
    else{
        parent[a]=b;
    }
}
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
int n=accounts.size();
int m=accounts[0].size();
std::unordered_map<string,int> email_id;
vector<int> parent(1005);
vector<int> rank(1005,1);
for(int i=0;i<n;i++){
	parent[i]=i;
	for(int j=1;j<accounts[i].size();j++){
		if(email_id.find(accounts[i][j])!=email_id.end()){
			Union(parent,rank,email_id[accounts[i][j]],i);
		}
		else{
			email_id[accounts[i][j]]=i;
		}
	}
}
std::unordered_map<int,std::vector<std::string>> id_email;
for(auto &el:email_id){
	int u_id=Get(parent,el.second);
	id_email[u_id].push_back(el.first);
}        
std::vector<vector<string>> ans;
for(auto &it:id_email){
	std::vector<string> email=it.second;
	std::sort(email.begin(),email.end());
	email.insert(email.begin(),accounts[it.first][0]);
	ans.push_back(email);
}
return ans;
}
};