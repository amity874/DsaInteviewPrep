#include<bits/stdc++.h>
using namespace std;
bool possible(int mid,string &t,string &p,std::vector<int>&arr){
  string temp= "";
  std:unordered_set<int>s;
  for(int i=0;i<mid;i++){
      s.insert(arr[i]-1);
  }
  for(int i=0;i<t.size();i++){
      if(s.count(i)==0){
          temp+=t[i];
      }
  }
  int i=0;
  int j=0;
  int temp_size=temp.size();
  int p_size=p.size();
  while (i<temp.size()&& j<p_size){
      if(temp[i]!=p[j]){
          i++;
      }
      else if(temp[i]==p[j]){
          i++;
          j++;
      }
  }
  return j==p_size; 
}
int main(int argc, char const *argv[])
{
    // std::string t;
    // std::cin>>t;
    // std::string p;
    // std::cin>>p;
    // int n=t.size();
    // std::vector<int>arr(n+1,0);
    // for(int i=1;i<=n;i++){
    //     std::cin>>arr[i];
    // }
    //    if(p.size()==0){
    //     return t.size();
    // }
    // int lo=0;
    // int hi=t.size()-p.size();
    // int ans=-1;
    // while(lo<=hi){
    //     int mid=lo+(hi-lo)/2;
    //     if(possible(mid,t,p,arr)){
    //         lo=mid+1;
    //         ans=mid;
    //     }
    //     else{
    //         hi=mid-1;
    //     }
    // }
    std::string t="ababcba";
    std::string p="abb";
   
    std::vector<int>arr={5,3,4,1,7,6,2};
    if(p.size()==0){
        std::cout<<t.size();
    }
    int lo=0;
    int hi=t.size()-p.size();
    int ans=-1;
    while (lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(possible(mid,t,p,arr)){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    std::cout<<ans;
return 0;
}