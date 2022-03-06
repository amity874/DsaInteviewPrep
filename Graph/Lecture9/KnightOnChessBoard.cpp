// https://www.interviewbit.com/problems/knight-on-chess-board/
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int dx[]={1,2,1,2,-1,-2,-1,-2};
    int dy[]={-2,-1,2,1,-2,-1,2,1}; 
    bool vis[A+2][B+2]={};
    std::queue<std::vector<int>> q;
    q.push({C,D,0});
    vis[C][D]=1;
    while(q.size())
    {
        auto top=q.front();
        q.pop();
        if(top[0]==E and top[1]==F)
            return top[2];
        
        for(int ii=0;ii<8;ii++)
        {
            int i=top[0]+dx[ii];
            int j=top[1]+dy[ii];
            if(i>=1 and j>=1 and i<=A and j<=B and !vis[i][j])
            {
                vis[i][j]=1;
                q.push({i,j,top[2]+1});
            }
        }
    }
    return -1;
}
