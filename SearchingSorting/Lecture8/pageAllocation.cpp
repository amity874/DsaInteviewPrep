#include<bits/stdc++.h>
bool possible(std::vector<int>&arr,int mid,int m,int n){
    int student=1;
    int curr_pages=0;
    for(int i=0;i<n;i++){
        if(curr_pages+arr[i]>mid){
            student++;
            curr_pages=arr[i];
            if(student>m){
                return false;
            }
        }
        else{
            curr_pages+=arr[i];
        }
    }
    return true;
}
int pageAllocation(std::vector<int>&arr,int n,int m){
    if(n<m){
        return -1;
    }
    int lo=arr[n-1];
    int hi=0;
    for(int i=0;i<n;i++){
        hi+=arr[i];
    }
    int ans=0;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(possible(arr,mid,m,n)){
            hi=mid-1;
            ans=mid;
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    std::vector<int>arr={12,34,67,90};
    int n=arr.size();
    int m=2;
    std::cout<<pageAllocation(arr,n,m);
return 0;
}