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
    vector<vector<int> > levelOrder(TreeNode *root) {
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
            if(v.empty())continue;
            q.push(NULL);
            ans.push_back(v);
        }
        return ans;
    }
};
//second edition
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        queue<TreeNode *> q1;
        if(!root)return ans;
        q1.push(root);
        while(!q1.empty()){
            queue<TreeNode *> q2;
            vector<int> v;
            while(!q1.empty()){
                TreeNode *tmp = q1.front();
                q1.pop();
                v.push_back(tmp -> val);
                if(tmp -> left)q2.push(tmp -> left);
                if(tmp -> right)q2.push(tmp -> right);
            }
            q1 = q2;
            ans.push_back(v);
        }
        return ans;
    }
};