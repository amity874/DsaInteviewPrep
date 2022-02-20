class Solution {
public:
    int findMin(vector<int>& arr) {
int n=arr.size();
int lo=0;
int hi=n-1;
int ans=arr[0];
while(lo<=hi){
	int mid=lo+(hi-lo)/2;
    if(arr[mid]<ans){
        hi=mid-1;
        ans=arr[mid];
    }
    else{
        lo=mid+1;
    }
} 
return ans;      
}
};