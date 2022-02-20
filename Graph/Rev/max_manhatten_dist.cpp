#include<bits/stdc++.h>
// --===Amit pandey--===
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll              long long int
#define ld              long double
#define mod             1000000007
#define inf             1e18
#define endl            "\n"
#define pb              push_back
#define vi              vector<ll>
#define vs              vector<string>
#define pii             pair<ll,ll>
#define ump             unordered_map
#define mp              make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n)          n.begin(),n.end()
#define ff              first
#define ss              second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n)         __builtin_popcount(n)
#define loop(i,a,b)     for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
bool isSafe(int x,int y,int n,int m){
    return (x>=0 and y>=0 and x<n and y<m);
}
int dfs(std::vector<std::vector<int>> grid,int n,int m){
    std::vector<std::vector<bool>> vis(n,std::vector<bool>(m,false));
    std::queue<std::pair<int,int>>qu;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
            qu.push({i,j});
            vis[i][j]=true;
            }
        }
    }
    loop(i,0,n-1){
        loop(j,0,m-1){
            std::cout<<vis[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    qu.push({-1,-1});
    int res=0;
    int xdir[4]={-1,1,0,0};
    int ydir[4]={0,0,-1,1};
    while(not qu.empty()){
        auto tp=qu.front();
        qu.pop();
          if(tp.ff== -1 and tp.ss== -1 and qu.size()>0){
            res++;
            qu.push({-1,-1});
            continue;
        }
        for(int d=0;d<4;d++){
            int x=tp.ff+xdir[d];
            int y=tp.ss+ydir[d];
            if((not isSafe(x,y,n,m)) or vis[x][y]){
                continue;
            }
          qu.push({x,y});
          vis[x][y]=true;
         }
    }
    return res;
}
int main(int argc, char const *argv[])
{
    file_i_o();
    std::vector<std::vector<int>> arr={{0, 1, 0},
           {0, 0, 1},
           {0, 0, 0}};
    std::cout<<dfs(arr,3,3);
return 0;
}