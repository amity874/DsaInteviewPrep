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
int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
int n=source.size();
std::map<int,map<int,int>> mp;
vector<int> parent(n+1);
vector<int> rank(n+1,1);
for(int i=0;i<=n;i++){
	parent[i]=i;
}
for(auto &el:allowedSwaps){
	Union(parent,rank,el[0],el[1]);
}
for(int i=0;i<n;i++){
	mp[Get(parent,i)][source[i]]++;
}
for(int i=0;i<n;i++){
	mp[Get(parent,i)][target[i]]--;
}
int ans=0;
for(auto &i:mp){
	auto x=i.second;
	for(auto &j:x){
		ans+=std::abs(j.second);
	}
}
return ans/2;
}
};