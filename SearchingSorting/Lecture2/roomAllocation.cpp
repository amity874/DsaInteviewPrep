#include<bits/stdc++.h>
#define ll long long int
ll calc(std::vector<int>&a1,std::vector<int>&a2){
    std::sort(a1.begin(),a1.end());
    std::sort(a2.begin(),a2.end());
    int n=a1.size();
    int i=1;
    int j=0;
    ll room=1;
    ll min_room=1;
    while(i<n &&j<n){
        if(a1[i]<=a2[j]){
            i++;
            room++;
        }
        else if(a1[i]>a2[j]){
            j++;
            room--;
        }
        if(room>min_room){
        min_room=room;
    }
    }
    return min_room;
}
int main(int argc, char const *argv[])
{
    std::vector<int>a1={900, 940, 950, 1100, 1500, 1800};
    std::vector<int>a2={910, 1200, 1120, 1130, 1900, 2000};
    std::cout<<calc(a1,a2);
return 0;
}