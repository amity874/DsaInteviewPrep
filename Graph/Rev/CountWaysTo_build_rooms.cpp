#define ll long long int
#define mx 100005
class Solution {
public:
 ll fact[100001];
 ll inv[100001];
ll mod = 1000000007;
ll dp[100001];
vector<ll> tree[100005];
ll pow__(ll a,ll b){
    ll res=1;
    a%=mod;
    while(b>0){
        if(b%2!=0){
            res=(res%mod*a%mod)%mod;
        }
        a=(a%mod*a%mod)%mod;
        b>>=1;
    }
    return res;
}
 int nCr(int n, int r){
        ll res = fact[n];
        res = (res * inv[r])%mod;
        res = (res * inv[n-r])%mod;
        return (int) res;
 }
void precompute(){
       if(fact[0]==1) return;
        
        fact[0] = 1;
        for(int i=1; i<=1e5; i++)
            fact[i] = (fact[i-1]*i)%mod;
        
        inv[100000] = pow__(fact[100000], mod-2LL);
        for(int i=1e5-1; i>=0; i--){
            inv[i] = (inv[i+1]*(i+1) )%mod;
        }
}
ll dfs(ll node,vector<ll>& cnt){
	     if(dp[node]!=-1) return dp[node];
        ll res = 1, Total_nodes = 0;
        for(auto &x:tree[node] ){
            int tmp = dfs(x,cnt);
            Total_nodes+= cnt[x];
            res = (nCr(Total_nodes, cnt[x]) * res)%mod;
            res = (res * tmp)%mod;
        }
        cnt[node] = (int) Total_nodes + 1; //self add
        return dp[node] = res;
}
int waysToBuildRooms(vector<int>& prevRoom) {
	precompute();
	int n=prevRoom.size();
for(int i=1;i<n;i++){
	tree[prevRoom[i]].push_back(i);
}
memset(dp,-1,sizeof(dp));
vector<ll> cnt(n,0);  
return dfs(0,cnt);    
}
};