#include<bits/stdc++.h>
int main(int argc, char const *argv[])
{
    std::vector<int>arr={7,3,5};
    int n=arr.size();
    int res=0;
    for(int i=0;i<31;i++){
        int cnt1=0;
        for(int j=0;j<n;j++){
            if((arr[j]>>i)&1){
                cnt1++;
            }
        }
        int temp=cnt1*(n-cnt1);
        res+=(1<<i)*temp;
    }
    std::cout<<res;
return 0;
}