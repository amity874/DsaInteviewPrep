#include<bits/stdc++.h>
using namespace std;

//function to display the 2-d array
void display(vector<vector<int>>& chess) {
  for (int i = 0; i < chess.size(); i++) {
    for (int j = 0; j < chess.size(); j++) {
      cout << chess[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int dir1[8]={-2,-1,1,2,2,1,-1,-2};
int dir2[8]={1,2,2,1,-1,-2,-2,-1};
void printKnightsTour(vector<vector<int>>& chess, int n, int r, int c, int upcomingMove) {
  //write your code here
	if(r<0 or c<0 or r>=chess.size() or c>=chess[0].size() or chess[r][c]>0){
		return;
	}
	else if(upcomingMove==chess.size()*chess.size()){
		chess[r][c]==upcomingMove;
		display(chess);
		chess[r][c]=0;
		return;
	}
	for(int i=0;i<8;i++){
	chess[r][c]=upcomingMove;
	printKnightsTour(chess,n,r+dir1[i],c+dir2[i],upcomingMove+1);
	chess[r][c]=0;
    }
}

int main() {

}