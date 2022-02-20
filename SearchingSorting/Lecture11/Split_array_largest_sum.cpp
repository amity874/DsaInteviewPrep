class Solution {
public:
   bool possible(vector<int>&arr,int mid,int m){
	int cnt=0;
	int alc=1;
	for(int i=0;i<arr.size();i++){
		cnt+=arr[i];
		if(cnt>mid){
			alc++;
			cnt=arr[i];
		}
	}
	return (alc<=m);
}
int splitArray(vector<int>& nums, int m) {
int n=nums.size();
std::vector<int>::iterator result = std::max_element(nums.begin(), nums.end());
int lo=nums[std::distance(nums.begin(), result)];
int hi=0;
for(int i=0;i<n;i++){
	hi+=nums[i];
}
        cout<<lo<<"   "<<hi;
int ans=0;
while(lo<=hi){
	int mid=lo+(hi-lo)/2;
	if(possible(nums,mid,m)){
		hi=mid-1;
		ans=mid;
	}
	else{
		lo=mid+1;
	}
} 
return ans;     
}
};