#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll              long long int
#define ld              long double
#define mod             1000000007
#define inf             1e18
#define endl            "\n"
#define pb              emplace_back
#define vi              vector<ll>
#define vs              vector<string>
#define pii             pair<ll,ll>
#define ump             unordered_map
#define mp              map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff              first
#define ss              second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b)     for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
#define log(args...)    { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;   
#define token(str,ch)   (std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


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
struct tripplet{
    int src;
    int dest;
    int wt;
};
int xdir[4]={-1,1,0,0};
int ydir[4]={0,0,-1,1};
int o_1_bfs(std::vector<std::vector<char>>&mat){
    int n=mat.size();
    int m=mat[0].size();
    int cost;
    std::deque<tripplet> dq;
    std::set<pair<int,int>> visited;
    dq.push_back({0,0,0});
    while(not dq.empty()){
        auto top=dq.front();
        visited.insert({top.src,top.dest});
        dq.pop_front();
        if(top.src==n-1 and top.dest==m-1){
            return top.wt;
        }
        loop(d,0,3){
            int x=top.src+xdir[d];
            int y=top.dest+ydir[d];
            if(visited.count({x,y})>0){
                continue;
            }
            if(x>=n or y>=m or x<0 or y<0){
                continue;
            }
            if(mat[x][y]=='U' and xdir[d]==-1 and ydir[d]==0){
                cost=0;
            }
            else if(mat[x][y]=='D' and xdir[d]==1 and ydir[d]==0){
                cost=0;
            }
            else if(mat[x][y]=='R' and xdir[d]==0 and ydir[d]==1){
                cost=0;
            }
            else if(mat[x][y]=='L' and xdir[d]==0 and ydir[d]==-1){
                cost=0;
            }
            else{
                cost+=1;
            }
            if(cost==1){
                dq.push_back({x,y,top.wt+cost});
            }
            else if(cost==0){
                dq.push_front({x,y,top.wt});
            }
        }
    }
    return -1;
}
int main(int argc, char const *argv[]) {
    file_i_o();
    int n,m;
    cin >> n>>m;
    std::vector<std::vector<char>> mat(n,std::vector<char>(m,' '));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin>>mat[i][j];
        }
    }
    std::cout<<o_1_bfs(mat);
    return 0;
}