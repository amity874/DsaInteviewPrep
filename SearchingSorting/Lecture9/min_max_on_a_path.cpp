#include<bits/stdc++.h>
using namespace  std;
int n;
std::vector<std::vector<std::pair<int,int> > >graph;
std::vector<int>parent(10005,0);

std::pair<int,std::vector<int>> bfs(int src,int dest,int d,int mid){
std::vector<bool>visited(100,false);
std::vector<int>dist(100,0);
std::queue<int>qu;
qu.push(src);
dist[src]=0;
parent[src]=src;
while(not qu.empty()){
    int curr=qu.front();
    qu.pop();
    for(auto &neighbour:graph[curr]){
        if(not visited[neighbour.first]){
            if(neighbour.second<=mid){
                visited[neighbour.first]=true;
                qu.push(neighbour.first);
                dist[neighbour.first]=dist[curr]+1;
                parent[neighbour.first]=curr;
            }
        }
    }
}
return {dist[dest],parent};
}
void binarySearch(int max_ele,int min_ele,int d){
    int lo=min_ele;
    int hi=max_ele;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        std::pair<int,std::vector<int>> res=bfs(0,n-1,d,mid);
        if(res.first==-1 or res.first>d){
            lo=mid+1;
        }
        else{
            hi=mid-1;
            parent=res.second;
            ans=res.first;
        }
    }
   std::cout<<ans<<"\n";
   if(ans!=-1){
       int vertex=n-1;
       std::vector<int>path;
       while(parent[vertex]!=vertex){
           path.push_back(vertex+1);
           vertex=parent[vertex];
       }
       path.push_back(vertex+1);
       for(int i=path.size()-1;i>=0;i--){
           std::cout<<path[i]<<"  ";
       }
   }
}
int main(int argc, char const *argv[])
{
    int e;
    int d;
    std::cin>>n>>e>>d;
    int max_ele=INT_MIN;
    int min_ele=INT_MAX;
    graph.resize(n,std::vector<std::pair<int,int>>());
    while(e--){
        int src;
        int dest;
        int wt;
        std::cin>>src>>dest>>wt;
        max_ele=std::max(max_ele,wt);
        min_ele=std::min(min_ele,wt);
        graph[src-1].push_back(std::make_pair(dest-1,wt));
    }
    std::cout<<min_ele<<" "<<max_ele<<"\n";
    binarySearch(max_ele,min_ele,d);
return 0;
}