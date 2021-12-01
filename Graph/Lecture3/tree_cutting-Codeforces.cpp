#include<bits/stdc++.h>
// https://codeforces.com/contest/1118/problem/F1
std::vector<std::list<int>>graph;
std::vector<int>color;
int red=0;
int blue=0;
int ans=0;
std::pair<int,int> travel(int node,int parent=-1){
    std::pair<int,int>myans(0,0);
    for(auto &neighbour:graph[node]){
        if(neighbour==parent){continue;}
        std::pair<int,int>n_ans=travel(neighbour,node);
        ans+=(n_ans.first==0 and n_ans.second==blue);
        ans+=(n_ans.first==red and n_ans.second==0);
        myans.first+=(n_ans.first);
        myans.second+=(n_ans.second);
    }
    if(color[node]==1){
        myans.first++;
    }
    else if(color[node]==2){
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