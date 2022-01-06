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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        std::vector<int> parent(n+1);
        std::vector<int> rank(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    Union(i,j,parent,rank);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                cnt++;
            }
        }
        return n-cnt;
    }
};