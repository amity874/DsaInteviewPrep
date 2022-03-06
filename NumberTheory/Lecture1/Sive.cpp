#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
std::bitset<MAX> isPrime;
std::vector<int>Prime;
void GeneratePrime() {
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2; i*i <= MAX; i++) {
        if(isPrime[i]) {
            for(ll j = i; j*i <= MAX; j++) {
                isPrime[j*i] = false;
            }
        }
    }
    Prime.push_back(2);
    for(int i = 3; i <= MAX; i+= 2) {
        if(isPrime[i]) Prime.push_back(i);
    }
}
void Seg_seive(ll a,ll b){
    std::vector<bool> res(b-1+1,true);
    if(b==1){
        a++;
    }
    for(int i=0;Prime[i]*Prime[i]<=b;i++){
        ll j=(a/Prime[i])*Prime[i];
        if(j<a){
            j+=Prime[i];
        }
        for(;j<=b;j++){
            if(j!=Prime[i]){
                res[j-a]=false;
            }
        }
    }
    for(int i=a;i<=b;i++){
        if(i==2 && res[i-a]){
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
    // Seg_seive(a,b);
    }
return 0;
}