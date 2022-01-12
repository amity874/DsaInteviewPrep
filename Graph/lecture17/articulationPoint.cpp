#include<bits/stdc++.h>
https://codeforces.com/blog/entry/71146 -->>>best article for articulation point
int disc[10005];
int low[10005];
int dtime=0;
std::vector<int> ap(1003);
std::vector<std::list<int>> g;
void dfs(int curr,int par){
    int newchild=0;
    disc[curr]=low[curr]=++dtime;
    for(auto &c:g[curr]){
        if(c==par)continue;
        if(!disc[c]){
        newchild++;
            dfs(c,curr);
            if(disc[curr]<=low[c]&& parent!=-1){
                ap[curr]=1;
            }
            low[curr]=std::min(low[curr],low[c]);
        }
        else{
            low[curr]=std::min(low[curr],disc[c]);
        }
    }
    if(parent==-1 && newchild>1){
        ap[curr]=1;
    }
}
vector<pair<int, int>> br;

int dfsBR(int u, int p) {
  low[u] = disc[u] = ++Time;
  for (int& v : adj[u]) {
    if (v == p) continue; // we don't want to go back through the same path.
                          // if we go back is because we found another way back
    if (!disc[v]) { // if V has not been discovered before
      dfsBR(v, u);  // recursive DFS call
      if (disc[u] < low[v]) // condition to find a bridge
        br.push_back({u, v});
      low[u] = min(low[u], low[v]); // low[v] might be an ancestor of u
    } else // if v was already discovered means that we found an ancestor
      low[u] = min(low[u], disc[v]); // finds the ancestor with the least discovery time
  }
}

void BR() {
  low = disc = vector<int>(adj.size());
  Time = 0;
  for (int u = 0; u < adj.size(); u++)
    if (!disc[u])
      dfsBR(u, u)
}
int main(int argc, char const *argv[])
{
return 0;
}