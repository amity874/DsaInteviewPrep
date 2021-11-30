#include<bits/stdc++.h>
int possible( std::vector<int>&a,int mid){
    int painter=1;
    int n=a.size();
    int i=0;
    int sum=0;
    while(i<n){
        sum+=a[i];
        if(sum>mid){
            sum=a[i];
            painter++;
        }
        i++;
    }
    return painter;
}
int main(int argc, char const *argv[])
{
    std::vector<int>a={10,10,10,10};
    int painter=2;
    int max_ele=INT_MIN;
    int sum=0;
    int n=a.size();
    for(int i=0;i<n;i++){
        max_ele=std::max(max_ele,a[i]);
        sum+=a[i];
    }
    int lo=max_ele;
    int hi=sum;
    int ans=0;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        int res=possible(a,mid);
        if(res<=painter){
            hi=mid-1;
            ans=mid;
        }
        else{
            lo=mid+1;
        }
    }
    std::cout<<ans;
return 0;
}