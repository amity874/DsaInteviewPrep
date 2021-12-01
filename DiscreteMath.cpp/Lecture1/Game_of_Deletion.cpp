#include<bits/stdc++.h>
// https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/game-of-destruction-f96cd509/
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<int>a(n,0);
    std::vector<int>b(n,0);
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
    for(int i=0;i<n;i++){
        std::cin>>b[i];
    }
    int r1=0,c1=0,r2=0,c2=0;
    for(int i=0;i<n;i++){
        c1=c1|a[i];
        r1+=a[i];
    }
    int revard1=r1-c1;
    for(int i=0;i<n;i++){
        c2=c2|b[i];
        r2+=b[i];
    }
    int revard2=r2-c2;
    if(revard1>revard2){
        std::cout<<1<<" "<<revard1-revard2;
    }
    else if(revard2>revard1){
        std::cout<<2<<" "<<revard2-revard1;
    }
    else{
        std::cout<<-1<<"\n";
    }
return 0;
}