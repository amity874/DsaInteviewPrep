#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll                 long long int
#define ld                long double
#define mod             1000000007
#define inf             1e18
#define endl            "\n"
#define pb                 emplace_back
#define vi              vector<ll>
#define vs                vector<string>
#define pii             pair<ll,ll>
#define ump                unordered_map
#define mp                 map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff                 first
#define ss                 second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b)     for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)     for(int i=(a);i>=(b);i--)
#define log(args...)     { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)    for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;    
#define token(str,ch)    (std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
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
std::vector<std::vector<std::pair<int,int> > >graph;
void addEdge(int u,int v,bool bidir=true,int wt=0){
    graph[u].push_back(std::make_pair(v,wt));
    if(bidir){
        graph[u].push_back(std::make_pair(u,wt));
    }
}
void Disp(){
    for(auto i:graph){
        //i is vector of pair
        for(auto j:i){
            std::cout<<"{"<<j.first<<","<<j.second<<"}";
        }
        std::cout<<"\n";
    }
}
void bfs(int src,int vertices){
    std::queue<int> qu;
    std::vector<bool>visited(vertices,false);
    qu.push(src);
    while (not qu.empty()){
        int currentNode=qu.front();
        cout<<currentNode<<"  ";
        visited[currentNode]=true;
        qu.pop();
        std::cout<<currentNode<<" ";
        for(auto neighbour:graph[currentNode]){
            // neighbour is a pair
            if(not visited[neighbour.first]){
                if(not visited[neighbour.first]){
                    qu.push(neighbour.first);
                    // visited[neighbour.first]=true;
                }
            }
        }
    }
}
int main(int argc, char const *argv[]) {
    file_i_o();
     int vertices,edges;
    std::cin>>vertices>>edges;
    graph.resize(vertices);
    while (edges--){
        int u,v,wt;
        std::cin>>u>>v>>wt;
        addEdge(u,v,true,wt);
    }
    // Disp();  
    bfs(1,vertices);
    return 0;
}