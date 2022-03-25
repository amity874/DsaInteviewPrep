#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
ll binaryExpoRec(ll a,ll b){
    if(b==1){
        return a;
    }
    ll res=binaryExpoRec(a,b/2);
    if(b%2==0){
        return ((res%mod)*(res%mod))%mod;
    }
    else{
        return ((res%mod)*(res%mod)*(a%mod))%mod;
    }
}
ll binaryExpoIter(ll a,ll b){
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
int main(int argc, char const *argv[])
{
    ll a,b;
    std::cin>>a>>b;
    std::cout<<binaryExpoRec(a,b)<<"\n";
    std::cout<<binaryExpoIter(a,b);
return 0;
}