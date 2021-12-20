#include<bits/stdc++.h>
std::vector<std::list<std::pair<int,int>>> g;
char dir(int d){
    if(d==0){
        return 'L';
    }
    else if(d==1){
        return 'R';
    }
    else if(d==2){
        return 'U';
    }
    else{
        return 'D';
    }
}
int level(char dir,int i,int j,int n,int m){
    if(dir=='L'){
        j--;
    }
    else if(dir=='R'){
        j++;
    }
    else if(dir=='U'){
        i--;
    }
    else if(dir=='D'){
        i++;
    }
    if(i<0 or j<0 or i>=n or j>=m){
        return -1;
    }
    return (i*m+j);
}
int bfs(int src,int n,int m){
    std::vector<int>dist(n*m,INT_MAX);
    std::deque<int>dq;
    dq.push_back(src);
    int d=((n-1)*(m)+(m-1));
    dist[src]=0;
    while(not dq.empty()){
        int tp=dq.front();
        dq.pop_front();
        for(auto &n:g[tp]){
            if(dist[n.first]>dist[tp]+n.second){
                dist[n.first]=dist[tp]+n.second;
                if(n.second==0){
                    dq.push_front(n.first);
                }
                else if(n.second==1){
                    dq.push_back(n.first);
                }
            }
        }
    }
    return dist[d];
}
int minmodification(std::vector<std::vector<char>> &mat,int n,int m){
    g.resize(n*m,std::list<std::pair<int,int>>());
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int d=0;d<4;d++){
                int lv=level(dir(d),i,j,n,m);
                if(lv==-1){
                    return -1;
                }
                if(dir(d)==mat[i][j]){
                    g[i*m+j].push_back({lv,0});
                }
                else{
                   g[i*m+j].push_back({lv,1});
                }
            }
        }
    }
    return bfs(0,n,m);
}
int main(int argc, char const *argv[])
{
    int n,m;
	std::cin >> n>>m;
    std::vector<std::vector<char>> mat(n,std::vector<char>(m,' '));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin>>mat[i][j];
        }
    }
    std::cout<<minmodification(mat,n,m);
return 0;
}