/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        std::queue<pair<TreeNode*,std::pair<int,int>>> qu;//{left,right}
        std::map<int,std::map<int,std::multiset<int>>> mp;
        qu.push({root,{0,0}});
        while(not qu.empty()){
            auto tp=qu.front();
            qu.pop();
            TreeNode* node=tp.first;
            int x=tp.second.first;
            int y=tp.second.second;
            mp[x][y].insert(node->val);
            if(node->left){
                qu.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                qu.push({node->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p:mp){
            vector<int> col;
            for(auto &q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};