/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//C++�ڴ��������ʱ����Բ������ַ�ʽ������������ΪTest�� Test test  ���� Test* pTest = new Test()��ǰ��ջ�ռ䣬���߶�
//new�����������Ҫָ�����
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        if(n == 0)return NULL;
        TreeNode *root = new TreeNode(num[n / 2]);//����Ҫnew������runtime error�˺þã���
        vector<int> leftArray;
        vector<int> rightArray;
        int i;
        for(i = 0;i < n / 2;i++)
            leftArray.push_back(num[i]);
        for(i = n / 2 + 1;i < n;i++)
            rightArray.push_back(num[i]);
        root -> left = sortedArrayToBST(leftArray);
        root -> right = sortedArrayToBST(rightArray);
        return root;
    }
};
//second edition
class Solution {
	vector<int> num;
public:
	TreeNode *sortedArrayToBST(vector<int> &number) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		num = number;
		return toBST(0,num.size() - 1);
	}
	TreeNode *toBST(int l,int r){
		if(l > r)return NULL;
		int m = (l + r) / 2;
		TreeNode *root = new TreeNode(num[m]);
		root -> left = toBST(l,m-1);
		root -> right = toBST(m+1,r);
		return root;
	}
};