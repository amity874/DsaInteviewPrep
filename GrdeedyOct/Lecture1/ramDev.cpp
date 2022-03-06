#include<bits/stdc++.h>
// https://www.codechef.com/problems/RAMDEV
#define ll long long int
int main(int argc, char const *argv[])
{
    ll l,b;
    std::cin>>l>>b;
    ll n;
    std::cin>>n;
    ll res=0;
    for(int i=0;i<n;i++){
        ll li,bi;
        std::cin>>li>>bi;
        res+=std::max(((li/l)*(bi/b)),(bi/l)*(li/b));
    } 
    std::cout<<res<<"\n";
return 0;
}