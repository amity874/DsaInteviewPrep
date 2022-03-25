class Solution {
public:
   int Get(std::vector<int>&parent,int a){
	 return parent[a]=((parent[a]==a)?a:Get(parent,parent[a]));
}
int cnt=1;
void Union(std::vector<int>&parent,std::vector<int>&rank,int a,int b){
	a=Get(parent,a);
    b=Get(parent,b);
    if(parent[a]!=parent[b]){
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
    else{
    	cnt++;
    }
}
int regionsBySlashes(vector<string>& grid) {
int n=grid.size();
int dots=n+1;
int sz=(n+1)*(n+1);
vector<int> parent(sz);
vector<int> rank(sz);
for(int i=0;i<sz;i++){
	parent[i]=i;
	rank[i]=1;
} 
for(int i=0;i<dots;i++){
	for(int j=0;j<dots;j++){
		if(i==0 or j==0 or i==dots-1 or j==dots-1){
			int curr_pos=(i*dots)+j;
			if(curr_pos!=0){
				Union(parent,rank,0,curr_pos);
			}
		}
	}
}
for(int i=0;i<n;i++){
	for(int j=0;j<grid[i].size();j++){
		if(grid[i][j]=='/'){
			int x=(i+1)*dots+j;
			int y=i*dots+(j+1);
			Union(parent,rank,x,y);
		}
		else if(grid[i][j]=='\\'){
			int pos1 = dots * i + j;
				int pos2 = dots * (i + 1) + (j + 1);
				Union(parent,rank,pos1,pos2);
		}
	}
}
    return cnt;	

}
};