#include<bits/stdc++.h>
using namespace std;

std::bitset<100> col,leftDiagonal,rightDiagonal;
void countQueenPath(int n,int cr,std::string osf){
	if(cr==n){
		std::cout<<osf<<"\n";
		return;
	}
	for(int i=0;i<n;i++){
		if(!col[i] and !leftDiagonal[(cr-i)+(n-1)]and !rightDiagonal[cr+i]){
			col[i]=leftDiagonal[(cr-i)+(n-1)] =rightDiagonal[cr+i]=1;
			countQueenPath(n,cr+1,osf+ to_string(cr)+" "+to_string(i)+", ");
			col[i]=leftDiagonal[(cr-i)+(n-1)] =rightDiagonal[cr+i]=0;
		}
	}
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> chess(n, vector<int> (n));

  countQueenPath(n,0,"");

}