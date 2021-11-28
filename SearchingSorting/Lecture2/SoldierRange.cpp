#include<bits/stdc++.h>
#define ll long long int
struct Soldier
{
    ll l,r;
};
bool cmp(Soldier a,Soldier b){
    return a.l<b.l;
}
ll soldierRange(std::vector<int>arr){
    int n=arr.size();
    std::vector<Soldier>Range(n);
    for(int i=0;i<n;i++){
        if(arr[i]>-1){
            Range[i].l=(i-arr[i]);
            Range[i].r=(i+arr[i]);
        }
    }
    std::sort(Range.begin(),Range.end(),cmp);
    int i=0;
    ll count=0;
    ll maxright=0;//rightmost range which guards the range(0,i)
    while(i<n){
        if(i==n){
            return -1;
        }
         if(Range[i].l>maxright){   //left boundaryb of the current soldier is greater than the index which we want to guard
            return -1;
        }
        ll current_max=Range[i].r;
        while(i<n && Range[i].l<=maxright){
            //  ith soldier is guarding an index which need not to be guarded
            current_max=std::max(current_max,Range[i].r);
            i++;
        }
        if(current_max<maxright){
            return -1;
        }
        count++;
        maxright=current_max+1;
        i++;
    }
    return count;
    return 1;
}
int main(int argc, char const *argv[])
{
    std::vector<int>arr={-1,2,2,-1,0,0};
    std::cout<<soldierRange(arr);
return 0;
}