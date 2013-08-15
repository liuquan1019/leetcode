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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = inorder.size();
        if(len == 0)return NULL;
        return buildTreePlus(preorder,inorder,0,len - 1,0,len - 1);
    }
    TreeNode *buildTreePlus(vector<int> &preorder, vector<int> &inorder,
                            int s1,int e1,int s2,int e2){
        if(s1 > e1)return NULL;
        TreeNode * root = new TreeNode(preorder[s1]);
        if(s1 == e1)return root;
        int i;
        for(i = s2;i <= e2;i++)
            if(inorder[i] == preorder[s1])break;        
        root -> left = buildTreePlus(preorder,inorder,s1 + 1,i - s2 + s1,s2,i - 1);
        root -> right = buildTreePlus(preorder,inorder,i - s2 + s1 + 1,e1,i + 1,e2);
        return root;
    }
};
//递归函数用数组下标表示区间，而不是负责局部数组，可以避免memory limit exceed