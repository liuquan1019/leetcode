/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//���������������õݹ飬Ҳ�����׻���Ϊ���������������������������������·�����������������������ϴ���
//INT_MIN - 100���ΪINT_MAX,��ΪԽ��
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
//second edition������ȫ����ֵ��ȫ�ֱ������͵ݹ麯������ֵ���ֲ���ֵ����˼·�ͻ������
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