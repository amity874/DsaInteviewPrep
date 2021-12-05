#include<bits/stdc++.h>
bool possible(int mid,int n,int m,int x,int y){
    int res=(m+(std::abs(n-mid))*y);
    return res>=x*mid;
}
int binarySearch(int n,int m,int x,int y){
    int lo=0;
    int hi=n;
    int ans=0;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(possible(mid,n,m,x,y)){
            lo=mid+1;
            ans=mid;
        }
        else{
            hi=mid-1;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int n,m,x,y;
    std::cin>>n>>m>>x>>y;
    std::cout<<binarySearch(n,m,x,y);
return 0;
}