#include<bits/stdc++.h>
bool possible(float mid,std::vector<int>&arr,int k){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i]/mid;
    }
    return sum>=k;
}
int main(int argc, char const *argv[])
{
    std::vector<int>arr={802,743,457,593};
    int k=11;
    float lo = 1.0f,hi = 1e10f;
    float mid=0.0;
    float ans=0.0;
    for(int i=1;i<150;i++){
        mid=float(lo+(hi-lo)/float(2));
        if(possible(mid,arr,k)){
            lo=mid;
            ans=mid;
        }
        else{
            hi=mid;
        }
    }
    std::cout<<ans;
return 0;
}