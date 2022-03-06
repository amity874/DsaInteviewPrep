class Solution {
public:
    struct Pair{
        int val;int x;int y;
        Pair(){}
        Pair(int a,int b,int c){
            x=a;
            y=b;
            val=c;
        }
        
    };
    struct compare{
      bool operator()(const Pair&a,const Pair&b){
          return a.val>b.val;
      }  
    };
    int swimInWater(vector<vector<int>>& grid) {
    int n=grid.size();
    int xdir[4]={0,0,-1,1};
    int ydir[4]={1,-1,0,0};
    int ans=INT_MIN;
    priority_queue<Pair,vector<Pair>,compare>pq;
    pq.push(Pair(0,0,grid[0][0]));
      auto tp=pq.top();
    cout<<tp.val<<" ";
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    while(not pq.empty()){
        auto tp=pq.top();
        int l=tp.x;
        int r=tp.y;
        int msf=tp.val;
        pq.pop();
        if(l==n-1 and  r==n-1){
            return msf;
        }
        if(visited[l][r]==true)
                continue;
        visited[l][r]=true;
        for(int dir=0;dir<4;dir++){
            int x=l+xdir[dir];
            int y=r+ydir[dir];
            if(x<0 or y<0 or x>=n or y>=n or visited[x][y]){
                continue;
            }
            else{
            pq.push(Pair(x,y,std::max(msf,grid[x][y])));
            }
        }
    }
return 0; 
}
};