#include<bits/stdc++.h>
int binary_search(std::vector<int>&arr,int target){
    int n=arr.size();
    int lo=0;
    int hi=n-1;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]>target){
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
    std::vector<int>arr={3,4,8,8,13,56,90};
    std::cout<<binary_search(arr,14);
return 0;
}