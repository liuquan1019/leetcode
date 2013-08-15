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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)return true;
        return isMirror(root -> left,root -> right);
    }
    bool isMirror(TreeNode *root1,TreeNode *root2){
        if(root1 == NULL && root2 == NULL)return true;
        if(root1 == NULL || root2 == NULL)return false;
        if(root1 -> val != root2 -> val)return false;
        return isMirror(root1 -> left,root2 -> right) && isMirror(root1 -> right,root2 -> left);

    }
};
//以下是递推方法：
class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(root == NULL)return true;
		vector<int> l,r;
		queue<TreeNode *> q1,q2;
		q1.push(root -> left);
		while(!q1.empty()){
			TreeNode *n = q1.front();
			q1.pop();
			if(n == NULL)l.push_back(-100000);
			else {
				l.push_back(n -> val);
				q1.push(n -> left);
				q1.push(n -> right);
			}   
		}
		q2.push(root -> right);
		while(!q2.empty()){
			TreeNode *n = q2.front();
			q2.pop();
			if(n == NULL)r.push_back(-100000);
			else {
				r.push_back(n -> val);
				q2.push(n -> right);
				q2.push(n -> left);
			}   
		}
		int s = l.size();
		if(s != r.size())return false;       
		for(int i = 0;i < s;i++)
			if(l[i] != r[i])return false;
		return true;
	}
};
//简化：
bool isSymmetric(TreeNode *root) {
	if(root == NULL) return true;

	queue<TreeNode *> lf, rt;
	lf.push(root->left);
	rt.push(root->right);
	TreeNode *l, *r;
	while(!lf.empty() && !rt.empty()) {
		l = lf.front(); r = rt.front();
		lf.pop(); rt.pop();
		if(l == NULL && r == NULL) continue;
		if(l == NULL || r == NULL) return false;
		if(l->val != r->val) return false;
		lf.push(l->left); lf.push(l->right);
		rt.push(r->right); rt.push(r->left);
	}
	if(lf.empty() && rt.empty()) return true;
	else return false;
}