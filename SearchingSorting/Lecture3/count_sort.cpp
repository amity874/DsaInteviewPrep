#include<bits/stdc++.h>
std::vector<int> count_sort(std::vector<int>&arr){
    //o(n+k)
    std::vector<int>::iterator result = std::min_element(arr.begin(), arr.end());
    int n1=arr[std::distance(arr.begin(), result)];
    std::vector<int>::iterator result1=std::max_element(arr.begin(),arr.end());
    int m1=arr[std::distance(arr.begin(), result1)];
    int k=(m1-n1+1);
    int n=arr.size();
    std::vector<int>freq(k,0);
    std::vector<int>output(n+1,0);
    //fill the freq array
    for(int i=0;i<n;i++){
        freq[arr[i]-n1]+=1;
    }
    //prefix sum
    for(int i=1;i<k;i++){
        freq[i]+=freq[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[freq[arr[i]-n1]]=arr[i];
        freq[arr[i]-n1]-=1;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i+1];
    }
    return arr;
}
int main(int argc, char const *argv[])
{
    std::vector<int>arr={5,2,6,7,2,1,0,3};
    std::vector<int>a=count_sort(arr);
    for(int i=0;i<a.size();i++){
        std::cout<<a[i]<<"  ";
    }
return 0;
}