#include<bits/stdc++.h>
// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/submissions/
 int largestSumAfterKNegations(std::vector<int>& nums, int k) {
        std::priority_queue<int,std::vector<int>,greater<int>> pq(nums.begin(),nums.end());
        int sum=0;
        while(k--){
            int x=pq.top();
            pq.pop();
            pq.push(-x);
            
        }
        while(not pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
 }
int main(int argc, char const *argv[])
{

return 0;
}