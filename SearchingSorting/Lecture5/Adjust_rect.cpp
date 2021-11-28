#include<bits/stdc++.h>
bool possible(int mid,int w,int h,int n){
    return (mid/w)*(mid/h)>=n;
}
int binarySearch(int n,int w,int h){
    int lo=0;
    int hi=n*(std::max(w,h));
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(possible(mid,w,h,n)){
            hi=mid-1;
            ans=mid;
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}
int main(int argc, char const *argv[]){
    int n;
    int w;
    int h;
    std::cin>>n>>w>>h;
    std::cout<<binarySearch(n,w,h);
return 0;
}