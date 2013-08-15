/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//������������������Ƿ����
//�������������½�ĵݹ飬���������游���ƣ����򵥣�����
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)return true;
        if(root -> left == NULL && root -> right == NULL)return true;
        TreeNode *p = new TreeNode(0);
        if(root -> left != NULL){
            if(root -> left -> val >= root -> val)return false;
			//�����ⲽ��������������ұ�֤�ȸ�С���ҽ�������֤�ȸ���
			//���²�������������ٿ�������Ϊ���ȸ���С����ر�����󡢱��ҽ��С����ͬ���ݹ鴦��
            p = root -> left;
            while(p -> right != NULL)p = p -> right;
            if(p -> val >= root -> val)return false;
        }
        if(root -> right != NULL){
            if(root -> right -> val <= root -> val)return false;
			//ͬ��
            p = root -> right;
            while(p -> left != NULL)p = p -> left;
            if(p -> val <= root -> val)return false;
        }
        
        return isValidBST(root -> left) && isValidBST(root -> right);
    }
};

//����

 class Solution {
 public:
     bool check(TreeNode *node, int leftVal, int rightVal){
         if (node == NULL)return true;    
         return leftVal < node->val && node->val < rightVal && 
			 check(node->left, leftVal, node->val) &&
             check(node->right, node->val, rightVal);
     }
     
     bool isValidBST(TreeNode *root) {
         return check(root, INT_MIN, INT_MAX);        
     }
 };
 //second edition
 class Solution {
 public:
	 bool isValidBST(TreeNode *root) {
		 // Start typing your C/C++ solution below
		 // DO NOT write int main() function
		 if(!root)return true;
		 if(!root -> left && !root -> right)return true;
		 if(root -> left){
			 TreeNode *tmp = root -> left;
			 if(tmp -> val >= root -> val)return false;
			 while(tmp -> right)tmp = tmp -> right;
			 if(tmp -> val >= root -> val)return false;
		 }
		 if(root -> right){
			 TreeNode *tmp = root -> right;
			 if(tmp -> val <= root -> val)return false;
			 while(tmp -> left)tmp = tmp -> left;
			 if(tmp -> val <= root -> val)return false;
		 }
		 return isValidBST(root -> left) && isValidBST(root -> right);
	 }
 };
 //third edition
 class Solution {
 public:
	 bool isValidBST(TreeNode *root) {
		 // Start typing your C/C++ solution below
		 // DO NOT write int main() function
		 return isValid(root,INT_MIN,INT_MAX);
	 }
	 bool isValid(TreeNode *root,int low,int high){
		 if(!root)return true;
		 if(root -> val <= low || root -> val >= high)return false;
		 return isValid(root -> left,low,root -> val) && isValid(root -> right,root -> val,high);
	 }
 };