class Solution {
public:
  int Get(std::vector<int>&parent,int a){
	 return parent[a]=((parent[a]==a)?a:Get(parent,parent[a]));
}
void Union(int a,int b,std::vector<int>&parent,std::vector<int>&rank){
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
bool equationsPossible(vector<string>& equations) {
	int n=equations.size();
	std::vector<int>parent(27);
	for(int i=0;i<=26;i++){
		parent[i]=i;
	}
	std::vector<int>rank(27,1);
	bool result=true;
	for(auto it:equations){
		  char ch=it[0];
        if(it[1]=='='){
			int a=it[0]-'a'+1;
			int b=it[3]-'a'+1;
        // std::cout<<" "<<a<<" "<<b;
			Union(a,b,parent,rank);
        }
	}
	for(auto it:equations){
		if(it[1]=='!'){
            std::cout<<"fd";
			int x=Get(parent,it[0]-'a'+1);
			int y=Get(parent,it[3]-'a'+1);
            std::cout<<x<<" "<<y;
			if(x==y){
				return false;
			}
        }
	}
	return true;
}
};