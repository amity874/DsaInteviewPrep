#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define MAX              1005
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
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
char arr[MAX][MAX];
char visited[MAX][MAX];
int n,m;
std::vector<std::vector<char>> dir{ {0,1,'R'},{1,0,'D'},{-1,0,'U'},{0,-1,'L'} };
void bfs(int i,int j){
	std::queue<std::pair<int,int>> qu;
	qu.push({i,j});
	visited[i][j]='_';
	while(not qu.empty()){
		int a=qu.front().first;
		int b=qu.front().second;
		qu.pop();
		for(auto d:dir){
			int x=a+d[0];
			int y=b+d[1];
			if(x>=0 and x<n){
				if(y>=0 and y<m){
				if(not visited[x][y] and arr[x][y] !='#'){
					qu.push({x,y});
					visited[x][y]=d[2];
				}
			}
		}
		}
	}
}
int main(int argc, char const *argv[]) {
	file_i_o();
	std::cin>>n>>m;
	loop(i,0,n-1){
		loop(j,0,m-1){
			std::cin>>arr[i][j];
		}
	}
	memset(visited,0,sizeof visited);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]=='A' && not visited[i][j]){
				bfs(i,j);
			}
		}
	}
	std::string res;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		if(arr[i][j]=='B' && visited[i][j]){
			int xdir=i;
			int ydir=j;
			while(visited[xdir][ydir]!='_'){
				for(auto &d:dir){
					if(d[2]==visited[xdir][ydir]){
						xdir-=d[0];
						ydir-=d[1];
						res.push_back(d[2]);
					}
				}
			}
		}	
		}
	}
	std::reverse(res.begin(),res.end());
	if(res.size()){
		std::cout<<"YES"<<"\n"<<res.size()<<"\n"<<res<<"\n";
	}
	else{
		std::cout<<"NO"<<"\n";
	}
	return 0;
}