#include<bits/stdc++.h>
int main(int argc, char const *argv[])
{
    std::vector<int>arr={2,3,3,4,4,7};
    int n=arr.size();
    int xr=0;
    for(int i=0;i<n;i++){
        xr=xr^arr[i];
    }
    int setBit=0;
    for(int i=0;i<31;i++){
        if((xr>>i)&1){
            setBit=i;
            break;
        }
    }
    int x=0;
    int y=0;
  for(int i=0;i<n;i++){
      if((arr[i]>>setBit)&1){
          x=x^arr[i];
      }
      else{
          y=y^arr[i];
      }
  }
  std::cout<<x<<" "<<y;
return 0;
}