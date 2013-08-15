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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        if(root == NULL)return ans;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        int cnt = 0;
        while(!q.empty()){
            v.clear();
            cnt++;
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
            if(cnt % 2 == 0)reverse(v.begin(),v.end());
            q.push(NULL);
            ans.push_back(v);
        }
        return ans;
    }
};