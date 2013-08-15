/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//法二：中序遍历，看是否递增
//法三：传入上下界的递归，巧妙引入祖父机制，更简单，见后
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
			//以下这步易忘，左结点的最右保证比根小，右结点的最左保证比跟大；
			//再下层的最右最左不用再考虑是因为若比根大、小，则必比左结点大、比右结点小，可同样递归处理
            p = root -> left;
            while(p -> right != NULL)p = p -> right;
            if(p -> val >= root -> val)return false;
        }
        if(root -> right != NULL){
            if(root -> right -> val <= root -> val)return false;
			//同上
            p = root -> right;
            while(p -> left != NULL)p = p -> left;
            if(p -> val <= root -> val)return false;
        }
        
        return isValidBST(root -> left) && isValidBST(root -> right);
    }
};

//法三

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