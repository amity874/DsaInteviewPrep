#include<bits/stdc++.h>
#define ll long long int
void  binarySearch(int n,std::vector<int>&x,std::vector<int>&v){
    float lo=0.0f;
    float hi=1e10f;
    float mid=0.0f;
    float ans=0.0f;
    for(int i=1;i<=150;i++){
       mid=lo+(hi-lo)/2;
       ll main_left=INT_MIN;
       ll main_right=INT_MAX;
       for(int i=0;i<n;i++){
           ll rangeLower=x[i]-mid*v[i];
           ll rangeUpper=x[i]+mid*v[i];
           main_left=std::max(main_left,rangeLower);
           main_right=std::min(main_right,rangeUpper);
       }
       if(main_left<=main_right){
           hi=mid;
           ans=mid;
       }
       else{
           lo=mid;
       }
    }
    std::cout<<std::setprecision(6)<<ans;
}
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<int>x(n,0);
    std::vector<int>v(n,0);
    for(int i=0;i<n;i++){
        std::cin>>x[i];
    }
    for(int i=0;i<n;i++){
        std::cin>>v[i];
    }
    binarySearch(n,x,v);
return 0;
}