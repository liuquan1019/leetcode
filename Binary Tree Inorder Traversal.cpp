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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        stack<TreeNode *> s;
        while(!s.empty() || root){
            if(root){
                s.push(root);
                root = root -> left;
            }
            else{
                root = s.top();
                s.pop();
                ans.push_back(root -> val);
                root = root -> right;
            }
        }
        return ans;
    }
};
//second edition:修改了原树，不好
class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> ans;
		if(!root)return ans;
		stack<TreeNode*> s;
		while(!s.empty() || root){
			if(!root){root = s.top();s.pop();}
			while(root -> left){
				s.push(root);
				TreeNode *tmp = root;
				root = root -> left;
				tmp -> left = NULL;
			}
			ans.push_back(root -> val);
			if(root -> right)s.push(root -> right);
			root = NULL;
		}
		return ans;
	}
};
//third edition
class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> ans;
		stack<TreeNode *> st;
		while(root || !st.empty()){
			if(root){st.push(root);root = root -> left;}
			else{
				root = st.top();
				st.pop();
				ans.push_back(root -> val);
				root = root -> right;
			}
		}
		return ans;
	}
};