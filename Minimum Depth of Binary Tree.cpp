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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)return 0;
        return getMinDepth(root,0);
    }
    int getMinDepth(TreeNode *root,int depth){
        if(root == NULL)return 0xffff;
        depth++;
        if(root -> left == NULL && root -> right ==NULL)return depth;
        return min(getMinDepth(root -> left,depth),getMinDepth(root -> right,depth));
    }
};
//second edition
class Solution {
public:
	int minDepth(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!root)return 0;
		return depth(root);
	}
	int depth(TreeNode *root){
		if(!root -> left && !root -> right)return 1;
		if(!root -> left)return minDepth(root -> right) + 1;
		if(!root -> right)return minDepth(root -> left) + 1;
		return min(minDepth(root->left),minDepth(root->right))+1;
	}
};