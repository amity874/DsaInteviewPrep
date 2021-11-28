#include<bits/stdc++.h>
float binary_search(int n,int precision){
    if(n==0 || n==1){
        return 1;
    }
    int lo=0;
    int hi=n;
    float ans=0.0;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid<n){
            lo=mid+1;
        }
        else{
            hi=mid-1;
            ans=hi;
        }
    }
    float inc=0.1;
    for(int i=0;i<precision;i++){
        while((ans*ans)<=n){
        ans+=inc;
    }
     ans=ans-inc;
     inc=inc/10;
    }
return ans;
}
int main(int argc, char const *argv[]){
    std::cout<<binary_search(14,3);
return 0;
}