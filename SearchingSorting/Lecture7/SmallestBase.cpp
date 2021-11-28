#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
ll pow__(ll a,ll b){
    if(b==1){
        return a;
    }
    ll res=pow__(a,b/2);
    if(b%2==0){
        return ((res%mod)*(res%mod))%mod;
    }
    else{
        return ((res%mod)*(res%mod)*(a%mod))%mod;
    }
}
ll possible(ll k,ll i){
    return ((pow__(k,i))/(k-1));
}
ll binarySearch(ll n){
for(int i=61;i>=2;i--){
    ll lo=2;
    ll hi=n-1;
    while(lo<=hi){
        ll mid=lo+(hi-lo)/2;
        if(possible(mid,i)==n){  //here mid represent smallest base
           return mid;
        }
        else if(possible(mid,i)>n){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
}
  return -1;
}
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::cout<<binarySearch(n);
return 0;
}