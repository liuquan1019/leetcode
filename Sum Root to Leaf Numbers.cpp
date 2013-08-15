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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)return 0;
        int sum = 0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *p = q.front();
            q.pop();
            if(p -> left){p -> left -> val += (p -> val) * 10;q.push(p -> left);}
            if(p -> right){p -> right -> val += (p -> val) * 10;q.push(p -> right);}
            if(!p -> left && !p -> right)sum += p -> val;
        }
        return sum;
    }
    
};
//second edition
class Solution {
public:
	int sumNumbers(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function 
		return sumTree(root,0);
	}
	int sumTree(TreeNode *root,int sum){
		if(!root)return sum;
		if(!root -> left && !root -> right)return 10 * sum + root -> val;
		int tmp = 0;
		if(root -> left)tmp += sumTree(root -> left,10*sum+root->val);
		if(root -> right)tmp += sumTree(root -> right,10*sum+root->val);
		return tmp;
	}
};