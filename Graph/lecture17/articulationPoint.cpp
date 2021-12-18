#include<bits/stdc++.h>
int disc[10005];
int low[10005];
int dtimes=0;
std::vector<std::list<int>> g;
void dfs(int curr,int par){
    int nc=0;
    disc[curr]=dtimes;
    low[curr]=dtimes;
    dtimes++;
    for(auto child:g[curr]){
        if(disc[child]==0){
            dfs(child,curr);
            nc++;
            low[curr]=std::min(low[curr],low[child]);

            if(par!=0 and low[child]>=disc[curr]){
                  std::cout<<"Articulation point found"<<curr<<"\n";
            }
            if(low[child]<disc[curr]){
                 std::cout<<"Bridge found"<<curr<<"-"<<child<<"\n";
            }
        }
        else{
            if(par!=child){
                low[curr]=std::min(low[curr],disc[child]);
            }
            }
        }
        if(par==0 && nc>=2){
             std::cout<<"Articulation point found"<<par<<"\n";
        }
}
int main(int argc, char const *argv[])
{
return 0;
}