#include<bits/stdc++.h>
std::vector<std::list<int>>graph;
std::vector<int>color;
int red=0;
int blue=0;
int ans=0;
std::pair<int,int>travel(int src,int par){
    std::pair<int,int>myans(0,0);
    for(auto &child:graph[src]){
        if(child!=par){
             std::pair<int,int>res=travel(child,src);
             ans+=(res.first==red and res.second==0);
             ans+=(res.first==0 and res.second==blue);
             myans.first+=(res.first);
             myans.second+=(res.second);
        }
    }
    if(color[src]==1){
        myans.first++;
    }
    else if(color[src]==2){
        myans.second++;
    }
    return myans;
}
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    graph.resize(n,std::list<int>());
    color.resize(n);
    for(int i=0;i<n;i++){
        std::cin>>color[i];
        red+=(color[i]==1);
        blue+=(color[i]==2);
    }
    for(int i=0;i<n-1;i++){
        int v,u;
        std::cin>>v>>u;
        v--;
        u--;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    travel(0,-1);
    std::cout<<ans;
return 0;
}