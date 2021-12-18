#include<bits/stdc++.h>
std::vector<int>g[100005];
std::vector<int>dist(100005,INT_MAX);
void BellmanFord_s(int src,int n){
    for(int i=0;i<n-1;i++){
        int j=0;
        while(g[j].size()!=0){
            if(dist[g[j][0]]+g[j][2]<g[j][1]){
                dist[g[j][1]]=dist[g[j][0]]+g[j][2];
            }
            j++;
        }
    }
}
int main(int argc, char const *argv[])
{
return 0;
}