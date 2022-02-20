class Solution {
public:
 void cnt(vector<int>&arr,vector<int>& inv_cnt,int lo,int mid,int hi){
  vector<int>temp(arr.size());
int k=0;
int i=lo;
int j=mid;
while((i<=(mid-1)) && (j<=hi)){
	if(arr[i]<=arr[j]){
		temp[k]=arr[i];
		i++;
	}
	else{
		inv_cnt[j]+=(mid-i);
		temp[k]=arr[j];
		j++;
	}
	k++;
}
	while(i<=(mid-1)){
		temp[k]=arr[i];
		i++;
		k++;
	}	
	while(j<=hi){
		temp[k]=arr[j];
		j++;
		k++;
	}
	for(int i=lo;i<=hi;i++){
		arr[i]=temp[i];
	}
}	
void merge(vector<int>&arr,vector<int>&inv_cnt,int lo,int hi){
	if(lo<hi){
		int mid=lo+(hi-lo)/2;
		merge(arr,inv_cnt,lo,mid);
		merge(arr,inv_cnt,mid+1,hi);
		cnt(arr,inv_cnt,lo,mid+1,hi);
	}
}
vector<int> countSmaller(vector<int>& nums) {
	int n=nums.size();
	vector<int> inv_cnt(nums.size());
	merge(nums,inv_cnt,0,n-1);
	return inv_cnt;	
}
};