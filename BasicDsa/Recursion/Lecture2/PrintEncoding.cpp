#include <iostream>
#include<string>
using namespace std;

void printEncoding(string str, string osf){
    // write your code here
	if(str.size()==0){
		std::cout<<osf<<" ";
		return;
	}
	else if(str.size()==1){
		if(str[0]=='0'){
		return;
	    }
	    else{
	    	int ch=str[0]-'0';
	    	char code=(char)('a'+(ch-1));
	    	std::cout<<osf+code;
	    }
	}
	else{
		char ch=str[0];
		std::string s1=str.substr(1);
		if(ch=='0'){
			return;
		}
		else{
			int c=ch-'0';
			char code=(char)('a'+(c-1));
			printEncoding(s1,osf+code);
		}
		std::string r1=str.substr(0,1);
		std::string r2=str.substr(2);
		int ch2=stoi(r1);
		if(ch2<26){
			char code=(char)('a'+(ch2-1));
			printEncoding(r2,code+osf);
		}
	}
}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    
}