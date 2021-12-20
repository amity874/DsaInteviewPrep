#include<bits/stdc++.h>
std::vector<std::vector<int>>graph;
void Addedge(int v,int u){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
bool dfsHelper(int src,int parent,std::vector<bool>&visited){
    visited[src]=true;
    for(int neighbour:graph[src]){
        if(not visited[neighbour]){
            bool cycle=dfsHelper(neighbour,src,visited);
            if(cycle){
                return true;
            }
        }
        else if(neighbour!=parent){
            return true;
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
return 0;
}