#include<bits/stdc++.h>
void SelectionSort(std::vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        bool swapped=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                std::swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(not swapped){
            return;
        }
    }
}
int main(int argc, char const *argv[])
{
    std::vector<int>arr={4,5,1,3,56,8,56,89};
    SelectionSort(arr);
    for(int i=0;i<arr.size();i++){
        std::cout<<arr[i]<<"  ";
    }
return 0;
}