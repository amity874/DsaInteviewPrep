#include<bits/stdc++.h>
int binary_search(std::vector<int>&arr){
    int n=arr.size();
    int lo=0;
    int hi=n-1;
    while(lo<hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]>arr[mid+1]){//this is for decreasing curve
        hi=mid;
        }
        else{
            lo=mid+1;
        }
    }
    return lo;
}
int main(int argc, char const *argv[])
{
    std::vector<int>arr={1,2,1,3,5,6,4};
    std::cout<<binary_search(arr);
return 0;
}