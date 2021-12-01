#include<bits/stdc++.h>
std::vector<std::list<int> > graph;
std::vector<std::vector<int> > result;
void all_path(int start, int end, std::vector<bool> &vis, std::vector<int> &path) {
    if(start==end){
        result.push_back(path);
        path.push_back(end);
        path.pop_back();
        return;
    }
    path.push_back(start);
    vis[start]=true;
    for(auto& neighbour:graph[start]){
        if(not vis[neighbour]){
            all_path(neighbour,end,vis,path);
        }
    }
    vis[start]=false;
    path.pop_back();
}
int main(int argc, char const *argv[])
{
return 0;
}