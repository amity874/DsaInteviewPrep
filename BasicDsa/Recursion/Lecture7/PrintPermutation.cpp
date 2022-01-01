#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void printPermutations(string &str, string asf){
    if(str.size()==0){
        std::cout<<asf<<"\n";
        return;
    }
    std::set<char>st;
for(int i=0;i<str.size();i++){
    if(st.count(str[i])==0){
    st.insert(str[i]);
    std::string left=str.substr(0,i);
    std::string right=str.substr(i+1);
    std::string ros=left+right;
    printPermutations(ros,asf+str[i]);
    }    
}
}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}