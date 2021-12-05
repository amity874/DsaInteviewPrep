#include<bits/stdc++.h>
#define ll long long int
ll Get(std::vector<int>&parent,ll a){
    return parent[a]=((parent[a]==a)?a:Get(parent,parent[a]));
}
void Union(std::vector<int>&parent,ll a,ll b){
    a=Get(parent,a);
    b=Get(parent,b);
    parent[b]=a;
}
int main(int argc, char const *argv[])
{
    int n,m;
    std::cin>>n>>m;
    std::vector<int>parent(n+2);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    while(m--){
        char ch;
        std::cin>>ch;
        int x;
        if(ch=='?'){
            std::cin>>x;
            int res=Get(parent,x);
            if(res==n+1){
                std::cout<<-1<<"\n";
            }
            else{
                std::cout<<res<<"\n";
            }
        }
        else{
            std::cin>>x;
            Union(parent,x+1,x);
        }
    }
return 0;
}