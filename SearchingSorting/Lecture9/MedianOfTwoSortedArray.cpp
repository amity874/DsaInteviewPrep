#include<bits/stdc++.h>
using namespace std;
#define inf   1e18
#define ll long long int
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a1, vector<int>& a2) {
    if(a2.size() < a1.size()) {
                               return findMedianSortedArrays(a2, a1);
                               };
    int n=a1.size();
 	int m=a2.size();
 	int lo=0;
 	int hi=n;
 	while(lo<=hi){
 		int c1=(lo+hi)>>1;
 		int c2=(n+m+1)/2 -c1;
        
 		int l1 = c1 == 0 ? INT_MIN : a1[c1-1];
        int l2 = c2 == 0 ? INT_MIN : a2[c2-1]; 
        
        int r1 = c1 == n ? INT_MAX : a1[c1];
        int r2 = c2 == m ? INT_MAX : a2[c2]; 
 	
        if(l1 <= r2 && l2 <= r1) {
                if( (n + m) % 2 == 0 ) 
                    return (max(l1, l2) + min(r1, r2)) / 2.0; 
                else 
                    return max(l1, l2); 
        }
        else if(l1 > r2) {
                hi = c1 - 1; 
        }
            else {
                lo = c1 + 1; 
        }
 	}
 	return 0.0;
    }
};