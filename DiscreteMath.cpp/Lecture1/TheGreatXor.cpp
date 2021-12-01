// https://www.hackerrank.com/challenges/the-great-xor/problem
#include<bits/stdc++.h>
#define ll long long int
int main(int argc, char const *argv[])
{
    ll t;
    std::cin>>t;
    while(t--){
        ll x;
        std::cin>>x;
        ll j=0;
        ll cnt=0;
        while(x>0){
            if((x&1)==0){
                cnt+=(ll)std::pow(2,j);
            }
            j++;
            x>>=1;
        }
        std::cout<<cnt<<"\n";
    }
return 0;
}