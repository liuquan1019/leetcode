/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)return true;
        if(!isBalanced(root -> left))return false;
        if(!isBalanced(root -> right))return false;
        int l = getDepth(root -> left,0);
        int r = getDepth(root -> right,0);
        if(l - r > 1 || r -l > 1)return false;
        return true;
    }
    int getDepth(TreeNode *root,int depth){
        if(root == NULL)return 0;
        depth++;
        if(root -> left == NULL && root -> right ==NULL)return depth;
        return max(getDepth(root -> left,depth),getDepth(root -> right,depth));
    }
};
//second edition
class Solution {
public:
	bool isBalanced(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int depth = 0;
		return isGood(root,depth);
	}
	bool isGood(TreeNode *root,int &depth){
		if(!root){depth = 0;return true;}
		int depth1 = 0,depth2 = 0;
		bool t1 = isGood(root -> left,depth1);
		bool t2 = isGood(root -> right,depth2);
		depth = max(depth1,depth2) + 1;
		return t1 && t2 && depth1 - depth2 >= -1 && depth1 - depth2 <= 1;
	}
};