/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//�ҵ�һ������Ϥ�����⣺�ݹ��ҵ����������е�Ҷ�ڵ��·��
class Solution {
    vector<vector<int> > ans;
    int SUM;
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        SUM = sum;
        ans.clear();//������ÿ�γ�ʼ����Ա����
        vector<int> route;
        getAllRoutes(root,route,0);
        return ans;
    }
    void getAllRoutes(TreeNode * root,vector<int> route,int routeSum){
        if(root == NULL)return;
        route.push_back(root -> val);
        routeSum += root -> val;
        if(root -> left == NULL && root -> right == NULL){
            if(routeSum == SUM)ans.push_back(route);
            return;
        }
        getAllRoutes(root -> left,route,routeSum);
        getAllRoutes(root -> right,route,routeSum);
    }
};
//second edition
class Solution {
	vector<vector<int> > ans;
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ans.clear();
		if(!root)return ans;
		vector<int> v;
		dfs(root,v,sum);
		return ans;
	}
	void dfs(TreeNode *root,vector<int> v,int sum){
		if(!root)return;
		v.push_back(root -> val);
		sum -= root -> val;
		if(!root -> left && !root -> right){
			if(sum == 0)ans.push_back(v);
			return;
		}
		dfs(root->left,v,sum);
		dfs(root->right,v,sum);
	}
};