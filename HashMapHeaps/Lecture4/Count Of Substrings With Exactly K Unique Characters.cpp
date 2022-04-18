#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				emplace_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
#define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
void removeEle(std::unordered_map<char,int> &mp,char &ch){
	if(mp[ch]==1){
		mp.erase(ch);
	}
	else{
		mp[ch]--;
	}
}
int getMx(std::string &str,int k){
	if(k==1){
		int ans=0;
		int n=str.size();
		std::unordered_map<char,int> mp;
		int i=-1;
		int j=-1;
		while(true){
			bool f1=false;
			bool f2=false;
			while(i<n-1){
				i++;
				f1=true;
				char ch=str[i];
				mp[ch]++;
				if(mp.size()>1){
				i--;
				removeEle(mp,ch);
				break;				
				}
			}
			while(j<i){
				f2=true;
				if(mp.size()==1){
					ans+=(i-j);
				}
				j++;
				char ch=str[j];
				removeEle(mp,ch);
				if(mp.size()==0){
					break;
				}
			}
			if(f1==false && f2==false){
				break;
			}
		}
		return ans;
	}
	int n=str.size();
	int ib=-1;
	int is=-1;
	int  j=-1;
	int ans=0;
	std::unordered_map<char,int> mp1;
	std::unordered_map<char,int> mp2;
	while(true){
		bool f1=false;
		bool f2=false;
		bool f3=false;
		while(ib<n-1){
			ib++;
			f1=true;
			char ch=str[ib];
			mp1[ch]++;
			if(mp1.size()==k+1){
				ib--;
				removeEle(mp1,ch);
				break;
			}
		}
		while(is<ib){
			is++;
			f1=true;
			char ch=str[is];
			mp2[ch]++;
			if(mp2.size()==k){
				is--;
				removeEle(mp2,ch);
				break;
			}
		}
		while(j<is){
			if(mp1.size()==k && mp2.size()==k-1){
				ans+=(ib-is);
			}
			f1=true;
			j++;
			char ch=str[j];
			removeEle(mp1,ch);
			removeEle(mp2,ch);
			if(mp1.size()<k or mp2.size()<k-1){
				break;
			}
		}
		if(f1==false && f2== false && f3==false){
			break;
		}
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	file_i_o();
	std::string str;
	std::cin>>str;
	int k;
	std::cin>>k;
	std::cout<<getMx(str,k);
	return 0;
}