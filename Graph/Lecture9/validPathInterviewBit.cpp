#include<bits/stdc++.h>
using namespace std;
bool valid(int x,int y,int A,int B){
    if(x<0||x>A||y<0||y>B){
        return false;
    }
    return true;
}
bool inCircle(int x,int y,int C,int D,vector<int>&E,vector<int>&F){
    for(int i=0;i<C;i++){
        if(((x-E[i])*(x-E[i])+(y-F[i])*(y-F[i]))<=(D*D))
         return true;
    }
    return false;
}
int dpx[8]={1,1,1,-1,-1,-1,0,0};
int dpy[8]={-1,1,0,1,-1,0,-1,1};
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
     // visited array
if(inCircle(0,0,C,D,E,F))
bool vis[A+1][B+1];
memset(vis,false,sizeof(vis));
queue<pair<int,int>> myque;
myque.push({0,0});
while(not myque.empty()){
    pair<int,int> temp=myque.front();
    myque.pop();
    vis[temp.first][temp.second]=true;
    for(int dir=0;dir<8;dir++){
        int x=temp.first+dpx[dir];
        int y=temp.second+dpy[dir];
        if(!vis[x][y] && !inCircle(x,y,C,D,E,F) && valid(A,B,C,D)){
            myque.push({x,y});
        }
    }
}
if(vis[C][D]){
    return "YES";
}
    return "NO";
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}