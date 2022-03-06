#include<bits/stdc++.h>
#define ll long long int
std::map<int,int>factor;
void calcFactor(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                factor[i]++;
                n/=i;
            }
        }
    }
    if(n>1){
        factor[n]++;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;   
    calcFactor(n);
    if(factor.size()>=3){
        std::cout<<"Yes";
        int ans=3;
        for(auto it=factor.begin();it!=factor.end();it++){
            if(ans>=1){
                std::cout<<(*it).first<<" ";
                ans--;
            }
        }
    }
    else if(factor.size()==1){
        int ans=factor.begin()->second;
        int n=factor.begin()->first;
        if(ans>=6){
            std::cout<<"Yes"<<"\n";
                for(int i=1;i<=3;i++){
                    std::cout<<pow(n,i)<<" ";
                }
        }
        else{
            std::cout<<"No";
        }
}
    else{
        if(factor.size()==2){
            int p1=factor.begin()->first;
            auto p2=factor.rbegin()->first;
            int ans=(n/(p1*p2));
            if(ans!=p1 and ans !=p2){
                std::cout<<"Yes"<<"\n";
                std::cout<<p1<<" "<<p2<<" "<<ans;
            }
            else{
                    std::cout<<"No";
            }
    }
}
return 0;
}