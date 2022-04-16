class Solution {
public:
void removeEle(std::unordered_map<int,int>&mp,int ch){
	if(mp[ch]==1){
		mp.erase(ch);
	}
	else{
		mp[ch]--;
	}
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
int n=nums.size()-1;
int ib=-1;
int is=-1;
int j=-1;
int ans=0;
std::unordered_map<int,int> mp1;
std::unordered_map<int,int> mp2;
if(k==1){
	int ans=0;
	int i=-1;
	int j=-1;
	std::unordered_map<int,int> mp;
	while(true){
		bool f1=false;
		bool f2=false;
		while(i<n){
			f1=true;
			i++;
			int ch=nums[i];
			mp[ch]++;
			if(mp.size()==2){
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
			int ch=nums[j];
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
while(true){
	bool f1=false;
	bool f2=false;
	bool f3=false;
	while(ib<n){
		ib++;
		f1=true;
		int ch=nums[ib];
		mp1[ch]++;
		if(mp1.size()==(k+1)){
			ib--;
			removeEle(mp1,ch);
			break;
		}
	}
	while(is<ib){
		is++;
		int ch=nums[is];
		f2=true;
		mp2[ch]++;
		if(mp2.size()==k){
			is--;
			removeEle(mp2,ch);
			break;
		}
	}
	while(j<ib){
		j++;
		f3=true;
		int ch=nums[j];
		if(mp1.size()==k && mp2.size()==k-1){
			ans+=(ib-is);
		}
		removeEle(mp1,ch);
		removeEle(mp2,ch);
		if(mp1.size()<k or mp2.size()<k-1){
			break;
		}
	}
	if(f1==false && f2==false && f3==false){
		break;
	}
}
return ans;         
}
};