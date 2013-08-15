/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)return;
        if(root -> left == NULL && root -> right == NULL)return;
        queue<TreeLinkNode *> q;
        q.push(root -> left);
        q.push(root -> right);
        int num = 2;
        bool flag = true;
        while(flag){
            for(int i = 1;i <= num;i++){
                TreeLinkNode* node = q.front();
                q.pop();
                if(i != num)node -> next = q.front();
                if(node -> left == NULL || node -> right == NULL)flag = false;
                q.push(node ->left);
                q.push(node ->right);
            }
            num *= 2;
        }
    }
};
//另一种递归做法
void connect(TreeLinkNode *root) {  
    if(root == NULL) return;  
    if(root->left != NULL)root->left->next = root->right;  
    if(root->right !=NULL)  
        root->right->next = root->next? root->next->left:NULL;  
    connect(root->left);  
    connect(root->right);  
}

//third edition
class Solution {
public:
	void connect(TreeLinkNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!root)return;
		if(!root -> left && !root -> right)return;
		root -> left -> next = root -> right;
		if(root -> next)root -> right -> next = root -> next -> left;
		connect(root -> left);
		connect(root -> right);
	}
};