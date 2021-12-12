// https://www.interviewbit.com/problems/418/
#include<bits/stdc++.h>
#define ll long long int
bool valid(int x,int y,int A,int B){
    if(x<0||x>A||y<0||y>B){
        return false;
    }
    return true;
}
bool Iscircle(int x,int y,int C,int D,std::vector<int>&E,std::vector<int>&F){
    for(int i=0;i<C;i++){
        if((x-E[i])*(x-E[i])+(y-F[i])*(y-F[i])<=(D*D)){
            return true;
        }
    }
    return false;
}
int dirx[8]={1,1,1,-1,-1,-1,0,0};
int diry[8]={-1,1,0,1,-1,0,-1,1};
std::string solve(int A, int B, int C, int D, std::vector<int> &E, std::vector<int> &F) {
    std::vector<std::vector<bool>> vis(A,std::vector<bool>(B,false));
    std::queue<std::pair<int,int>> qu;
    qu.push({0,0});
    vis[0][0]=true;
    if(Iscircle(A,B,C,D,E,F)){
        return "NO";
    }
    while(not qu.empty()){
        auto top=qu.front();
        qu.pop();
        int x=top.first;
        int y=top.second;
        for(int i=0;i<8;i++){
            int nx=x+dirx[i];
            int ny=y+diry[i];
            if(!vis[nx][ny] and valid(nx,ny,A,B) and !Iscircle(nx,ny,C,D,E,F)){
                vis[nx][ny]=true;
                qu.push({nx,ny});
            }
        }
    }
    if(vis[A][B]){
        return "YES";
    }
    else{
        return "NO";
    }
}
int main(int argc, char const *argv[])
{

return 0;
}