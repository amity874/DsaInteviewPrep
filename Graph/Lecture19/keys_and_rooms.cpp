class Solution {
public:
    int count;
    void dfs(vector<vector<int>>& rooms,std::vector<bool>&vis,int src){
        vis[src]=true;
        count++;
        for(auto i:rooms[src]){
            if(vis[i]==0){
                dfs(rooms,vis,i);
            }
     }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
         count=0;
        std::vector<bool>vis(n,false);
        dfs(rooms,vis,0);;
        return count==n;
    }
};