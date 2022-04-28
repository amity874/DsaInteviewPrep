class Solution {
public:
    string fractionToDecimal(long numerator, long denominator) {
        if(not numerator){
            return "0";
        }
        string ans;
    	if(numerator>0 ^ denominator>0){
    		ans+='-';
    	}
    	long q=labs(numerator/denominator);
    	long r=labs(numerator%denominator);
    	ans+=to_string(q);
        cout<<ans;
    	if(r==0){
    		return ans;
    	}
    	ans+='.';
    	std::unordered_map<long,int> mp;
    		while(r){
    			if(mp.count(r)){
    				long idx=mp[r];
    				ans.insert(idx,"(");
    				ans+=')';
    				break;
    			}
    				mp[r]=ans.size();
    				r*=10;
    				q=labs(r/denominator);
    				r=labs(r%denominator);
    				ans.append(to_string(q));
    	}
    	return ans;
    }
};