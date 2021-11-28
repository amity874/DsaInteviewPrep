#include<bits/stdc++.h>
int possible(int mid){
    return (mid*((mid+1)))/2;
}
int binarySearch(int n){
    int lo=1;
    int hi=n;
    int ans=0;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(possible(mid)<=n){
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
    int n;
    std::cin>>n;
    std::cout<<binarySearch(n);
return 0;
}