#include<iostream>
#include<bits/stdc++.h>
using namespace std;
std::vector<int> merge(std::vector<int>&arr1,std::vector<int>&arr2){
    int n=arr1.size();
    int m=arr2.size();
    int i=0;
    int j=0;
    int k=0;
    std::vector<int>aux(n+m,0);
    while (i<n && j<m){
        if(arr1[i]<=arr2[j]){
            aux[k]=arr1[i];
            i++;
        }
        else{
            aux[k]=arr2[j];
            j++;
        }
        k++;
    }
    while (i<n){
        aux[k]=arr1[i];
        i++;
        k++;
    }  
    while (j<m){
        aux[k]=arr2[j];
        j++;
        k++;
    }
    return aux;
}
void inplaceMerge(std::vector<int>&a1,std::vector<int> &a2,int start,int m,int e){
    int start2=m+1;
    while (start<=m&& start2<=e){
        if(a1[start]<=a2[start2]){
            start++;
        }
        else{
            int temp=a1[start2];
            int idx=start2;
            while (idx!=start){
                /* code */
                a1[idx]=a1[idx-1];
                idx--;
            }
            a1[start]=temp;
            m++;
            start++;
            start2++;
        }
    }
     
}
int main(int argc, char const *argv[])
{
    std::vector<int>arr={3,6,7,8,56,78};
    std:vector<int>arr1={6,7,8,23,45,78,90};
    int n=arr.size()+arr1.size();
    inplaceMerge(arr,arr1,0,n/2,n);
    for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
    }
    return 0;
}
