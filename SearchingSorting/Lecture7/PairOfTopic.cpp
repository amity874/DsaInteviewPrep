// https://codeforces.com/contest/1324/problem/D
#include<bits/stdc++.h>
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
    for(int i=0;i<n;i++){
        std::cin>>b[i];
    }
    int c[n];
    for(int i=0;i<n;i++){
        c[i]=b[i]-a[i];
    }
    std::sort(c,c+n);
    int ans=0;
    for(int i=0;i<n;i++){
        auto it=std::lower_bound(c+i+1,c+n,-c[i]);
        int idx=(it-c);
        ans+=idx-(i+1);
    }
    std::cout<<ans;
return 0;
}