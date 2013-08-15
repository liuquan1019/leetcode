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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root ==NULL)return;
        if(root -> left ==NULL && root -> right == NULL)return;
        flatten(root -> left);
        flatten(root -> right);
        TreeNode * temp = root -> right;
        root -> right = root -> left;
        root -> left = NULL;//没有这句就是runtime error
        while(root -> right !=NULL)root = root -> right;
        root -> right = temp;
    }
};
//second edition
class Solution {
public:
	void flatten(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!root)return;
		if(!root -> left && !root -> right)return;
		TreeNode *tmp = root -> right;
		if(root -> left){
			root -> right = root -> left;
			flatten(root -> left);
			while(root -> right){root -> left = NULL;root = root -> right;} 
		}
		root -> right = tmp;
		flatten(tmp);
	}
};
//third edition
class Solution {
public:
	void flatten(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		TreeNode *prev = NULL;
		flatten(root,prev);
	}
	void flatten(TreeNode *root, TreeNode *&prev){
		TreeNode *r = NULL;
		if(root)r = root -> right;
		if(prev){prev -> right = root;prev -> left = NULL;}
		if(!root)return;
		prev = root;
		flatten(root -> left,prev);
		while(prev -> right)prev = prev -> right;
		flatten(r,prev);
	}
};
//法二：其实就是按前序遍历拍，可用非递归的栈
class Solution {  
public:  
	void flatten(TreeNode *root) {  
		// Start typing your C/C++ solution below  
		// DO NOT write int main() function  
		if (root == NULL) return;  
		stack<TreeNode*> stk;  
		stk.push(root);  
		TreeNode np(0);  
		TreeNode* ptr = &np;  
		while(!stk.empty())  
		{  
			TreeNode* p = stk.top();  
			stk.pop();  
			if(p != NULL)  
			{  
				stk.push(p->right);  
				stk.push(p->left);  

				ptr->right = p;  
				ptr = p;  
				ptr->left = NULL;  
			}  
		}  
	}  
};