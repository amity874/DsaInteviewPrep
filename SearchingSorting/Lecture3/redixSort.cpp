#include<bits/stdc++.h>
void count_sort(std::vector<int>&arr,int pos){
    //o(n+k)
    int k=10;
    int n=arr.size();
    std::vector<int>freq(k,0);
    std::vector<int>output(n+1,0);
    //fill the freq array
    for(int i=0;i<n;i++){
        freq[((arr[i])/pos)%10]+=1;
    }
    //prefix sum
    for(int i=1;i<k;i++){
        freq[i]+=freq[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[freq[((arr[i])/pos)%10]]=arr[i];
        freq[(arr[i]/pos)%10]-=1;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i+1];
    }
}
std::vector<int> redix_sort(std::vector<int>&arr){
    std::vector<int>::iterator result = std::max_element(arr.begin(), arr.end());
    int n1=arr[std::distance(arr.begin(), result)];
    int exponent=1;
    while(exponent<=n1){
        count_sort(arr,exponent);
        exponent*=10;
    }
    return arr;
} 
int main(int argc, char const *argv[])
{
    std::vector<int>arr={5,2,6,7,2,1,0,3};
    std::vector<int>a=redix_sort(arr);
    for(int i=0;i<a.size();i++){
        std::cout<<a[i]<<"  ";
    }
return 0;
}