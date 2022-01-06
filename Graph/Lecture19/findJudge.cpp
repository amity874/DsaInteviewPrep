class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::vector<int>inout(n+1);
        for(auto &it:trust){
            inout[it[0]]--;
            inout[it[1]]++;
        }
        for(int i=1;i<=n;i++){
            std::cout<<inout[i]<<"  ";
        }
        for(int i=1;i<=n;i++){
            if(inout[i]==n-1)return i;
        }
        return -1;
    }
};