class Solution {
public:
   int Get(std::vector<int> &parent,int a){
    return parent[a]=((parent[a]==a)?a:Get(parent,parent[a]));
}
bool Union(std::vector<int> &parent,std::vector<int> &rank,int a,int b){
    a=Get(parent,a);
    b=Get(parent,b);
    if(a!=b){
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
    	return true;
    }
    return false;    
}
vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
	int n=edges.size();
	std::vector<int>indegree(n+1);
	std::vector<int>parent(n+1);
	std::vector<int>rank(n+1);
	for(int i=0;i<=n;i++){
		parent[i]=i;
		rank[i]=1;
		indegree[i]=-1;
	}
	int bl1=-1;
	int bl2=-1;
	for(int i=0;i<n;i++){
		int u=edges[i][0];
		int v=edges[i][1];
		if(indegree[v]==-1){
			indegree[v]=i;
		}
		else{
			bl1=i;
			bl2=indegree[v];
		}
	}
	for(int i=0;i<n;i++){
		if(i==bl1){
			continue;
		}
		int u=edges[i][0];
		int v=edges[i][1];
		bool flag=Union(parent,rank,u,v);
		if(flag){
			if(bl1==-1){
				return edges[i];//case 2
			}
			else{
				return edges[bl2];//case 3
			}
		}
	}
	return edges[bl1];
}

};