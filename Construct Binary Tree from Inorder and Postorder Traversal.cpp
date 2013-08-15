/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//第一次做图省事没有加区间参数，而是复制数组，但递归调用导致空间开销太大，超过预定值后显示runtime error
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = inorder.size();
        if(len == 0)return NULL;
        return buildTreePlus(inorder,postorder,0,len - 1,0,len - 1);
    }
    TreeNode *buildTreePlus(vector<int> &inorder, vector<int> &postorder,
                            int s1,int e1,int s2,int e2){
        if(s1 > e1)return NULL;
        TreeNode * root = new TreeNode(postorder[e2]);
        if(s1 == e1)return root;
        int i;
        for(i = s1;i <= e1;i++)
            if(inorder[i] == postorder[e2])break;        
        root -> left = buildTreePlus(inorder,postorder,s1,i - 1,s2,i - s1 + s2 - 1);
        root -> right = buildTreePlus(inorder,postorder,i + 1,e1,i - s1 + s2,e2 - 1);
        return root;
    }
};