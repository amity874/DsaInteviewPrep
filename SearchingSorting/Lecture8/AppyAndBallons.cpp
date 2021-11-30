#include<bits/stdc++.h>
#define ll long long int
using namespace std;
// https://www.codechef.com/problems/HMAPPY
ll GetMinCandies( std::vector<ll>&A,std::vector<ll>&B,ll mid,ll ballon){
    ll ballons=0;
    for(int i=0;i<A.size();i++){
        ll ballon_compansated=mid/B[i];
        ll curr=std::max(0LL,(A[i]-ballon_compansated));
        ballons+=curr;
    }
  return ballons<=ballon;
}
int main(int argc, char const *argv[])
{
    /* code */
    ll ballons;
    ll n;
    cin>>n>>ballons;
    std::vector<ll>A(n,0);
    std::vector<ll>B(n,0);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    ll lo=0;
    ll hi=LLONG_MAX;
    ll ans=0;
    while (lo<=hi){
        ll mid=lo+(hi-lo)/2;
        if(GetMinCandies(A,B,mid,ballons)){
            hi=mid-1;
            ans=mid;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<ans;
    
    return 0;
}

