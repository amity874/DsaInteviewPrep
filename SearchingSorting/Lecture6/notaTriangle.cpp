#include<bits/stdc++.h>
int binarySearch(int *arr,int n){
    std::sort(arr,arr+n);
    int ans=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            int upper1 = std::upper_bound(arr,arr+n,arr[i]+arr[j])-arr;
           ans+=(n-upper1);
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int  arr[]={4,2,10};
    std::cout<<binarySearch(arr,3);
return 0;
}