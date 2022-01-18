class Solution {
    #define pii             pair<int,int>
public:
   pii parent[505][505];
pii Get(pii a){
	return parent[a.first][a.second]=(parent[a.first][a.second]==a)?a:Get(parent[a.first][a.second]);
}
void Union(pii a,pii b){
	a=Get(a);
	b=Get(b);
	parent[a.first][a.second]=b;
}
vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix){
	int n=matrix.size();
	int m=matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            parent[i][j]={i,j};
        }
    }
	std::vector<std::vector<int>> arr(n,std::vector<int>(m));
	std::vector<std::pair<int,int>>g[n][m];
	std::vector<int>row(n,0);
	std::vector<int>col(m,0);
	std::map<int,std::vector<std::vector<std::pair<int,int>>>> mp;
	for(int i=0;i<n;i++){
		std::unordered_map<int,pair<int,int>> mp;
		for(int j=0;j<m;j++){
			int el=matrix[i][j];
			if(mp.count(el))Union({i,j},mp[el]);
			mp[el]={i,j};
		}
	}
	for(int j=0;j<m;j++){
		std::unordered_map<int,pair<int,int>> mp;
		for(int i=0;i<n;i++){
			int el=matrix[i][j];
			if(mp.count(el))Union({i,j},mp[el]);
			mp[el]={i,j};
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			// int el=matrix[i][j];
			auto x=Get({i,j});
			g[x.first][x.second].push_back({i,j});
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j].size()){
			int el=matrix[i][j];
			mp[el].push_back(g[i][j]);
		}
		}
	}
	for(auto &i:mp){
		for(auto &j:i.second){
		int ans=0;
			for(auto &k:j){
				int x=k.first;
				int y=k.second;
				ans =std::max(ans,1+std::max(row[x],col[y]));
			}
			for(auto &k:j){
				int x=k.first;
				int y=k.second;
				arr[x][y]=ans;
				row[x]=std::max(row[x],ans);
				col[y]=std::max(col[y],ans);
			}
		}
	}
	return arr;
}
};