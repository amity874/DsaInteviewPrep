class Dsu{
private:
       int cnt;
		std::vector<int> rank;
		std::vector<int> parent;
public:
	Dsu(int n){
         cnt = n;
        for (int i = 0; i < n; ++i) {
            parent.push_back(-1);
            rank.push_back(1);
        }
	}
	int Get(int x){
        if(parent[x]==-1){
            return x;
        }
		return (parent[x]==x?x:Get(parent[x]));
	}
	bool Union(int a,int b){
		 int rootx = Get(a);
        int rooty = Get(b);
        
        if (rootx == rooty) return false;
        if (rank[rootx] < rank[rooty]) {
            parent[rootx] = rooty;
            rank[rooty] += rank[rootx];
        }else {
            parent[rooty] = rootx;
            rank[rootx] += rank[rooty];
        }
        --cnt;
        return true;
	}
    int getCnt(){
        return this->cnt;
    }
};
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
 Dsu DS(n);
        
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) 
                if (!DS.Union(i, leftChild[i])) return false;
        }
        
        for (int i = 0; i < n; ++i) {
            if (rightChild[i] != -1) {
                if (DS.Get(rightChild[i]) != rightChild[i]) return false; //node already is a child
                if (!DS.Union(i, rightChild[i])) return false;
            }       
        }
        
        return DS.getCnt() == 1;
    }
};