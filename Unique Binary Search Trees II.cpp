/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//长期出错原因在于只存指针，随后修改了该指针指向的内容导致wrong answer，故需要创建新的实在内容被指向
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        vector<vector<TreeNode *> > ans(20);
        ans[0].push_back(NULL);
        TreeNode *root = new TreeNode(1);
        ans[1].push_back(root);
        int N = n;
        int i,j,k;
        for(n = 2;n <= N;n++)
            for(i = 1;i <= n;i++)              
                for(j = 0;j < ans[i - 1].size();j++)
                    for(k = 0;k < ans[n - i].size();k++){
                        TreeNode *p = new TreeNode(i);
                        p -> left = modify(ans[i - 1][j],0);
                        p -> right = modify(ans[n - i][k],i);
                        ans[n].push_back(p);
                    }
        return ans[N];
    }
    TreeNode* modify(TreeNode *root,int i){
        if(root == NULL)return NULL;
        TreeNode *q = new TreeNode(root -> val + i);
        q -> left = modify(root -> left,i);
        q -> right = modify(root -> right,i);
        return q;
    }

};
//second edition:与上基本一致，一个小错是update时对左右子的处理应不同
class Solution {
public:
	vector<TreeNode *> generateTrees(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<TreeNode *> ans;
		vector<vector<TreeNode *> > all;
		ans.push_back(NULL);
		if(n == 0)return ans;
		all.push_back(ans);
		for(int i = 1;i <= n;i++){
			ans.clear();
			for(int j = 1;j <= i;j++)
				for(int l = 0;l < all[j-1].size();l++)
					for(int r = 0;r < all[i-j].size();r++){
						TreeNode *node = new TreeNode(j);
						node -> left = update(all[j-1][l],j,true);
						node -> right = update(all[i-j][r],j,false);
						ans.push_back(node);
					}
					if(i<n)all.push_back(ans);
		}
		return ans;
	}
	TreeNode* update(TreeNode *root,int j,bool left){
		if(!root)return NULL;
		TreeNode *root2 = new TreeNode(root -> val);
		if(!left)root2 -> val += j;
		root2 -> left = update(root -> left,j,left);
		root2 -> right = update(root -> right,j,left);
		return root2;
	}
};