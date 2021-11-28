#include<bits/stdc++.h>
int binarySearch(std::vector<int>&arr){
    int n=arr.size();
    std::vector<int>lhs;
    std::vector<int>rhs;
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            for(int c=0;c<n;c++){
                lhs.push_back((arr[a]*arr[b])+arr[c]);
            }
        }
    }
    for(int d=0;d<n;d++){
        for(int e=0;e<n;e++){
            for(int f=0;f<n;f++){
                if(arr[d]==0){
                    continue;
                }
                rhs.push_back((arr[f]+arr[e])*arr[d]);
            }
        }
    }
    std::sort(lhs.begin(),lhs.end());
    std::sort(rhs.begin(),rhs.end());
    // for(int i=0;i<lhs.size();i++){
    //     std::cout<<lhs[i]<<",";
    // }
    // std::cout<<"\n";
    // for(int i=0;i<rhs.size();i++){
    //     std::cout<<rhs[i]<<",";
    // }
    int ans=0;
    for(int i=0;i<lhs.size();i++){
        auto t=std::lower_bound(rhs.begin(),rhs.end(),lhs[i]);
        int x1=std::distance(t,rhs.begin());
        auto t2=std::upper_bound(rhs.begin(),rhs.end(),lhs[i]);
        int x2=std::distance(t2,rhs.begin());
    //    std::cout<<x1<<" "<<x2<<" ";
    ans+=std::abs(x2-x1);
    }
    return ans;
}
int main(int argc, char const *argv[])
{
  std::vector<int>arr={-1,1};
    std::cout<<binarySearch(arr);
return 0;
}