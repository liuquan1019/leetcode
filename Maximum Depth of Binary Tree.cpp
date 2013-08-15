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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)return 0;
        return getMaxDepth(root,0);
    }
    int getMaxDepth(TreeNode *root,int depth){
        if(root == NULL)return 0;
        depth++;
        if(root -> left == NULL && root -> right ==NULL)return depth;
        return max(getMaxDepth(root -> left,depth),getMaxDepth(root -> right,depth));
    }
};
//second edition
class Solution {
public:
	int maxDepth(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!root)return 0;
		return max(maxDepth(root->left),maxDepth(root->right))+1;
	}
};
