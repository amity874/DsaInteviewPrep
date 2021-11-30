#include<bits/stdc++.h>
#define ll long long int
// https://www.spoj.com/problems/AGGRCOW/
bool possible(ll mid,ll c,std::vector<ll>&arr){
    ll last_pos=arr[0];
    ll cnt=1;
    for(int i=1;i<arr.size();i++){
        int current_pos=arr[i];
        if((current_pos-last_pos)>=mid){
            cnt++;
            last_pos=arr[i];
        }
        if(cnt==c){
            return true;
        }
    }
    return false;
}
ll AggressiveCows(std::vector<ll>&arr,int n,int c){
    std::sort(arr.begin(),arr.end());
    ll lo=1;
    ll hi=arr[n-1];
    ll ans=0;
    while(lo<=hi){
        ll mid=lo+(hi-lo)/2;
        if(possible(mid,c,arr)){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    ll t;
    std::cin>>t;
    while(t--){
        ll n,c;
        std::cin>>n>>c;
        std::vector<ll>arr(n,0);
        for(int i=0;i<n;i++){
            std::cin>>arr[i];
        }
        std::cout<<AggressiveCows(arr,n,c)<<"\n";
    }
return 0;
}