#include<bits/stdc++.h>
int binary_search(std::vector<int>&arr,int target){
    int n=arr.size();
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
return 0;
}