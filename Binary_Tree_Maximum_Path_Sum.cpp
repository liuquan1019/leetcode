/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//看到二叉树便想用递归，也很容易划分为左右子树，但是陷阱在于左子树的最大路径如果不过其根，则不能再向上传递
//INT_MIN - 100则便为INT_MAX,因为越界
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)return 0;
    	int maxSum = INT_MIN;
		maxPathSum(root,maxSum);
		return maxSum;
	}
	int maxPathSum(TreeNode *root,int &maxSum) {
		if(root == NULL)return 0;
        int temp1 = maxPathSum(root -> left,maxSum);
        int temp2 = maxPathSum(root -> right,maxSum);
		int maxBranch = temp1 > temp2 ? temp1 : temp2;
		int temp = max(maxBranch + root -> val,root -> val,temp1 + temp2 + root -> val);
        if(temp >= maxSum)maxSum = temp;
		if(maxBranch > 0)return maxBranch + root -> val;
		return root -> val;
    }
private:
    int max(int a,int b,int c){
        if(a >= b && a >= c)return a;
        else if(b >= a && b >= c)return b;
        return c;
    }
};
//second edition区分清全局最值（全局变量）和递归函数返回值（局部最值），思路就会很清晰
class Solution {
	int maxSumAll;
public:
	int maxPathSum(TreeNode *root) {
		maxSumAll = INT_MIN;
		if(!root)return 0;
		maxPath(root);
		return maxSumAll;
	}
	int maxPath(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!root)return 0;
		int l = maxPath(root -> left);
		int r = maxPath(root -> right);
		int maxSum = max(0,l,r) + root -> val;
		maxSumAll = max(maxSumAll,maxSum,l + r + root -> val);
		return maxSum;
	}
	int max(int a,int b,int c){
		if(a >= b && a >= c)return a;
		if(b >= c)return b;
		return c;
	}
};