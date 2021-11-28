#include<bits/stdc++.h>
void WaveSort(std::vector<int>&arr){
   int n=arr.size();
   int i=0;
   while(i<n){
       if(i>0 && arr[i-1]>arr[i]){
           std::swap(arr[i-1],arr[i]);
       }
       if(i<n-1 && arr[i]<arr[i+1]){
           std::swap(arr[i],arr[i+1]);
       }
       i+=2;
   }
}
int main(int argc, char const *argv[])
{
    std::vector<int>arr={5,2,6,7,2,1,0,3};
    WaveSort(arr);
    for(int i=0;i<arr.size();i++){
        std::cout<<arr[i]<<"  ";
    }
return 0;
}