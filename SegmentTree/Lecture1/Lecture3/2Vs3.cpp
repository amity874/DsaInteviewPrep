#include<bits/stdc++.h>
// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/2-vs-3/
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
ll n;
const ll maxN=2e5+5;
ll tree[4*maxN],arr[maxN];
ll poW[maxN];
void calcPow(){
    poW[0]=1;
    for(int i=1;i<100000;i++){
        poW[i]=(poW[i-1]*2)%3;
    }
}
void build(ll tidx=1,ll l=0,ll r=n-1){
    if(l==r){
        tree[tidx]=arr[l];
        return;
    }
    else{
    ll m=mid(l,r);
    build(2*tidx,l,m);
    build(2*tidx+1,m+1,r);
    tree[tidx]=(tree[2*tidx]*poW[r-mid]+tree[2*tidx+1])%3;
  }
}
void update(ll pos,ll val,ll nl=0,ll nr=n-1,ll tidx=1){
    if(nl==nr){
        tree[tidx]=val;
        arr[pos]=val;
    }
    else{
        ll m=mid(nl,nr);
        if(m<=pos){
            update(pos,val,nl,m,2*tidx);
        }
        else{
            update(pos,val,m+1,nr,2*tidx+1);
        }
        tree[tidx]=(tidx[2*tidx]*poW[nr-m]+tree[2*tidx+1])%mod;
    }
}
ll query(ll l,ll r,ll nl=0,ll nr=n-1){
    if(r<nl or l> nr){
        return 0;
    }
    if(l<=nl && r>=nr){
        return tree[2*tidx]*(poW[nr-r])%3;
    }
    ll m=mid(nl,nr);
    ll p=query(l,r,nl,m);
    ll q=query(l,r,m+1,nr);
    return (p1+p1)%3;
}
int main(int argc, char const *argv[]) {
    file_i_o();
    
    return 0;
}