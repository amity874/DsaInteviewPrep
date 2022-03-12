#include<bits/stdc++.h>
#define ll long long int
#define max 100005
std::vector<ll>seive(max,0);
std::vector<ll>Prime;
void generatePrime(){
    for(int i=1;i<max;i++){
        seive[i]=i;
    }
    for(int i=2;i<max;i++){
        if(seive[i]==i){
            Prime.push_back(i);
        }
        for(int j=0;j<Prime.size()&&Prime[j]<=seive[i]&&i*Prime[j]<max;j++){
            seive[i*Prime[j]]=Prime[j];
        }
    }
}
int main(int argc, char const *argv[])
{
    generatePrime();
     for(int i = 2; i < 100; i++) {
        std::cout<<seive[i]<<"\n";
    }
return 0;
}