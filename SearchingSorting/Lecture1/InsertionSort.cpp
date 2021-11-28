#include<bits/stdc++.h>
void InsertionSort(std::vector<int>&arr){
  int n=arr.size();
  for(int i=0;i<n;i++){
      int key=arr[i];
      int j=i-1;
      while(j>=0 && key<arr[j]){
          arr[j+1]=arr[j];
          j--;
      }
      arr[j+1]=key;
  }
}
int main(int argc, char const *argv[])
{
    std::vector<int>arr={4,5,1,3,56,8,56,89};
    InsertionSort(arr);
    for(int i=0;i<arr.size();i++){
        std::cout<<arr[i]<<"  ";
    }
return 0;
}