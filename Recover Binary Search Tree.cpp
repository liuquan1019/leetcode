/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//二叉搜索树先想中序遍历（即得递增数列），下方法适合任意打乱而非仅两个
class Solution {
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode *> node;
        vector<int> value;
        inOrder(root,node,value);
        sort(value.begin(),value.end());
        for(int i = 0;i < value.size();i++)
            node[i] -> val = value[i];
    }
    void inOrder(TreeNode * root,vector<TreeNode *> &node,vector<int> &value){
        if(root == NULL)return;
        inOrder(root -> left,node,value);
        node.push_back(root);
        value.push_back(root -> val);
        inOrder(root -> right,node,value);
    }
};
//second edition：在看code后如下。答案在于两个逆序对分别的首和尾；
class Solution {
	TreeNode *first; 
	TreeNode *second;
public:
	void recoverTree(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		first = NULL;second = NULL;
		TreeNode * prev = NULL;
		inorder(root,prev);
		int tmp = first -> val;
		first -> val = second -> val;
		second -> val = tmp;
	}
	void inorder(TreeNode *root,TreeNode *&prev){//注意！要修改prev指针，故传其引用，否则runtime
		if(!root)return;                         //只传指针则修改的是指向的内容
		inorder(root -> left,prev);
		if(prev && prev -> val > root -> val){
			if(!first)first = prev;
			second = root;
		}
		prev = root;
		inorder(root -> right,prev);
	}
};