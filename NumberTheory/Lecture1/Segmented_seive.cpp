#include<bits/stdc++.h>
// Problem Link - https://www.spoj.com/problems/PRIME1/cstart=10
#define ll long long int
#define max  100000
std::bitset<max> IsPrime;
std::vector<int>primes;
void  GeneratePrime(){
    IsPrime.set();
    for(int i=2;i*i<=max;i++){
        if(IsPrime[i]){
            for(int j=i;j*i<=max;j++){
                IsPrime[j*i]=false;
            }
        }
    }
    primes.push_back(2);
    for(int i=2;i<=max;i++){
        if(IsPrime[i]){
            primes.push_back(i);
        }
    }
}
void SegSive(ll a,ll b){
    std::vector<bool>seg(b-a+1,true);
    if(b==1){
        a++;
    }
    for(int i=0;primes[i]*primes[i]<=b;i++){
        int p=primes[i];
        int j=(a/p)*p;
        if(j<a){
            j+=p;
        }
        for(;j<=b;j+=p){
            if(j!=p){
                seg[j-a]=false;
            }
        }
    }
    for(int i=a;i<=b;i++){
        if(i==2 or seg[i-a]){
            std::cout<<i<<"\n";
        }
    }
}
int main(int argc, char const *argv[]){
    GeneratePrime();
    ll t;
    std::cin>>t;
    while(t--){
        ll a,b;
        std::cin>>a>>b;
    SegSive(a,b);
    }
return 0;
}
