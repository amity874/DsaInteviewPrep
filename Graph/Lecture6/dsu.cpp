#include<bits/stdc++.h>
#define ll long long int
#define vi              std::vector<ll>
ll Get(vi &parent,ll a){
    return parent[a]=((parent[a]==a)?a:Get(parent,parent[a]));
}
void Union(vi &parent,vi &rank,ll a,ll b){
    a=Get(parent,a);
    b=Get(parent,b);
    if(rank[a]==rank[b]){
        rank[a]++;
    }
    if(rank[a]>rank[b]){
        parent[b]=a;
    }
    else{
        parent[a]=b;
    }
}
int main(int argc, char const *argv[])
{
return 0;
}