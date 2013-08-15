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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        if(root == NULL)return ans;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while(!q.empty()){
            v.clear();
            root = q.front();
            while(root != NULL){
                q.pop();
                if(root -> left != NULL)q.push(root -> left);
                if(root -> right != NULL)q.push(root -> right);
                v.push_back(root -> val);
                root = q.front();
            }
            q.pop();
			if(v.empty())continue;//少了这句话一直memory limit exceeded
            q.push(NULL);
            ans.push_back(v);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};