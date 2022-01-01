#include<bits/stdc++.h>
void solution(std::string &str,std::string osf,int count,int idx){
	if(idx==str.size()){
		std::cout<<osf<<"\n";
		return;
	}
	if(count>0){
	solution(str,osf+str[idx],0,idx+1);		
	}
	else{
	solution(str,osf+str[idx],0,idx+1);
	}
	solution(str,osf,count+1,idx+1);
}
int main(int argc, char const *argv[]) {
	// file_i_o();
	std::string str;
	std::cin>>str;
	solution(str,"",0,0);
	return 0;
}