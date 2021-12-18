#include<bits/stdc++.h>
std::vector<std::list<int>>g;
bool bfs(int src){
    std::unordered_set<int>sets[2];
    std::queue<int>qu;
    qu.push(src);
    sets[0].insert(src);
    while(not qu.empty()){
        int curr=qu.front();
        qu.pop();
        int s=(sets[0].count(curr)>0?0:1);
        for(auto &neighbour:g[curr]){
            if(sets[0].count(neighbour)==0 and sets[1].count(neighbour)==0){
                sets[1-s].insert(neighbour);
                qu.push(neighbour);
            }
            else if(sets[s].count(neighbour)>0){
                return false;
            }
        }
    }
    //if we want to acces color then check sets
    return true;
}
int main(int argc, char const *argv[])
{
return 0;
}