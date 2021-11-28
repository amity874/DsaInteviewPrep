#include<bits/stdc++.h>
int getMin(int start,int end,std::vector<int>&arr){
    int minidx=arr[start];
    start++;
    while(start<end){
        if(arr[start]<arr[minidx]){
            minidx=start;
        }
        start++;
    }
}
void selectionSort(std::vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int min=getMin(i,n,arr);
        if(i!=min){
            std::swap(arr[i],arr[min]);
        }
    }
}
int main(int argc, char const *argv[])
{
    std::vector<int>arr={4,5,1,3,56,8,56,89};
    selectionSort(arr);
    for(int i=0;i<arr.size();i++){
        std::cout<<arr[i]<<"  ";
    }
return 0;
}