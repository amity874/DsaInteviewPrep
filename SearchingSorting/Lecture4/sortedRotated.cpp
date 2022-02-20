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
        else if(arr[mid]>=arr[lo]){
            if(target>=arr[lo] && target<arr[mid]){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        //case 2
        else{
            if(target<=arr[hi]&& target>arr[mid]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    std::vector<int>arr={3,4,8,8,13,56,90};
    std::cout<<binary_search(arr,13);
return 0;
}