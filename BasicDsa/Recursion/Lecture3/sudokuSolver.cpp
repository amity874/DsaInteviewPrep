#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll        long long int
#define ld        long double
#define mod             1000000007
#define inf             1e18
#define endl      "\n"
#define pb        emplace_back
#define vi              vector<ll>
#define vii             vector<vector<int>>
#define vs        vector<string>
#define pii             pair<ll,ll>
#define ump       unordered_map
#define mp        map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff        first
#define ss        second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b)   for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
#define log(args...)  { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << endl;
  err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
void display(vii& arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << "\n";
  }
}
bool isItsafe(vii& arr, int x, int y,int pos){
	for(int j=0;j<arr[0].size();j++){
		if(arr[x][j]==pos){
			return false;
		}
	}
	for(int i=0;i<arr.size();i++){
		if(arr[i][y]==pos){
			return false;
		}
	}
	int d1=(x/3)*3;
	int d2=(y/3)*3;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(arr[i+d1][j+d2]==pos){
				return false;
			}
		}
	}
	return true;
}
void solveSudoku(std::vector<std::vector<int>>&arr, int i, int j) {
    if(i==arr.size()){
        display(arr);
        return;
    }
	int nr=0;
	int nc=0;
	if(j==arr[0].size()-1){
		nr=i+1;
		nc=0;
	}
	else{
		nr=i;
		nc=j+1;
	}
	if(arr[i][j]!=0){
		solveSudoku(arr,nr,nc);
	}
	else{
		for(int pos=1;pos<=9;pos++){
			if(isItsafe(arr,i,j,pos)){
				arr[i][j]=pos;
				solveSudoku(arr,nr,nc);
				arr[i][j]=0;
			}
		}
	}
}
int main(int argc, char const* argv[]) {
  // file_i_o();
  std::vector<std::vector<int>> board(10, std::vector<int>(10));
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      std::cin >> arr[i][j];
    }
  }
  solveSudoku(arr, 0, 0);
  return 0;
}