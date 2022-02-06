#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int

struct TrieNode{
	TrieNode *left;
	TrieNode *right;
};
struct Trie {
	TrieNode *root;
	Trie(){
		root=new TrieNode();
	}
	 void insert(ll n) {
     TrieNode *curr = root;
     for(int i = 31; i >= 0; i--) {
         int bit = (n >> i) & 1;
         if(bit == 0) {
             if(curr->left == NULL) {
                 curr->left = new TrieNode();
             }
             curr = curr->left;
         } else {
             if(curr->right == NULL) {
                 curr->right = new TrieNode();
             }
             curr = curr->right;
         }
     }
 }
	ll get_max(int value) {
    ll curr_xor = 0;
    TrieNode *curr = root;
    for(int i = 31; i >= 0; i--) {
        int bit = (value >> i) & 1;
        if(bit == 0) {
            // we desire to have a 1 that means right child should be there
            if(curr->right != NULL) {
                curr = curr->right;
                curr_xor += (1 << i);
            } else {
                curr = curr->left;
            }
        } else {
            // we desire to have a 0 that means left child should be there
            if(curr->left != NULL) {
                curr = curr->left;
                curr_xor += (1 << i);
            } else {
                curr = curr->right;
            }
        }
    }
    return curr_xor;
}
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	vector<int> ans(queries.size(), 0); 
    vector<pair<int, pair<int,int>>> offlineQueries; 
    sort(arr.begin(), arr.end()); 
    int index = 0;
    for(auto &it: queries) {
        offlineQueries.push_back({it[1],{it[0], index++}}); 
    }
    sort(offlineQueries.begin(), offlineQueries.end()); 
    int i = 0; 
    int n = arr.size(); 
    Trie trie; 
    
    for(auto &it : offlineQueries) {
        while(i < n && arr[i] <= it.first) {
            trie.insert(arr[i]); 
            i++; 
        }
        if(i!=0) ans[it.second.second] = trie.get_max(it.second.first); 
        else ans[it.second.second] = -1; 
    }
    return ans; 
}