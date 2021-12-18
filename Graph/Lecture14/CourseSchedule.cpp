#include<bits/stdc++.h>
class Solution {
public:
  std::vector<int> topo(int n, std::vector<std::list<int>>&g){
    std::vector<bool>vis(n+1,false);
    std::vector<int> indegree(n+1);
    for(int i=0;i<n;i++){
        for(int j:g[i]){
            indegree[j]++;
        }
    }
    std::queue<int>qu;
    std::vector<int>res;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            qu.push(i);
        }
    }
    while(not qu.empty()){
        int tp=qu.front();
        res.push_back(tp);
        qu.pop();
        for(auto & ne:g[tp]){
            indegree[ne]--;
            if(indegree[ne]==0){
                qu.push(ne);
            }
        }
    }
    return res;
}
std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::list<int>> g(numCourses);
    int n=prerequisites.size();
    int m=prerequisites[0].size();
    for(auto &el:prerequisites){
        g[el[1]].push_back(el[0]);
    }
    auto res=topo(numCourses,g);
    if(res.size()!=numCourses){
        return std::vector<int>();
    }
    return res;
}
};
int main(int argc, char const *argv[])
{
return 0;
}