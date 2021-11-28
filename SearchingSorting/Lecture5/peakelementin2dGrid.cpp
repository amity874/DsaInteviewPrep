#include<bits/stdc++.h>
int findmax(std::vector<int>&arr){
    int n=arr.size();
    int max_element=0;
    int idx=-1;
    for(int i=0;i<n;i++){
        if(max_element<arr[i]){
            max_element=arr[i];
            idx=i;
        }
    }
    return idx;
}
std::pair<int,int> binarySearch(std::vector<std::vector<int>>&arr){
    int n=arr.size();
    int m=arr[0].size();
    int lo=0;
    int hi=n-1;
    int max_idx=-1;
    while(lo<hi){
        int mid=lo+(hi-lo)/2;
        max_idx=findmax(arr[mid]);
        if(arr[mid][max_idx]<arr[mid+1][max_idx]){//increasing curve
        lo=mid+1;
        }
        else{//decreasing curve
            hi=mid;
        }
    }
    max_idx=(findmax(arr[lo]));
    return {lo,max_idx};
}
int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>>arr={{-1,-1,-1,-1,-1},{-1,10,20,15,-1},{-1,21,30,14,-1},{-1,7,16,32,-1},{-1,-1,-1,-1,-1}};
    std::pair<int,int>p=binarySearch(arr);
    std::cout<<p.first<<" "<<p.second;
return 0;
}