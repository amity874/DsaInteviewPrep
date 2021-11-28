#include<bits/stdc++.h>
bool possible(int mid,int x,int y,int n){
    return (mid/x)+(mid/y)>=n-1;
}
int binarySearch(int n,int x,int y){
    if(n==1){
        return std::min(x,y);
    }
    int lo=0;
    int hi=std::max(x,y)*n;
    int ans=0;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(possible(mid,x,y,n)){
            hi=mid-1;
            ans=mid;
        }
        else{
            lo=mid+1;
        }
    }
    return ans+std::min(x,y);//min(x,y)for first making a copy then we apply further pocedure 
}
int main(int argc, char const *argv[])
{
    int n,x,y;
    std::cin>>n>>x>>y;
    std::cout<<binarySearch(n,x,y);
return 0;
}