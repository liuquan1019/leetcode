/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p = head, *q = head;
        int n = 0;
        while(p!= NULL){n++;p = p -> next;}
        if(n == 0)return NULL;
        if(n == 1){TreeNode *root = new TreeNode(head -> val);return root;}
        n = n / 2;
        while(n > 1){q = q -> next;n--;}
        p = q -> next;
        q -> next = NULL;
        TreeNode *root = new TreeNode(p -> val);
        root -> left = sortedListToBST(head);
        root -> right = sortedListToBST(p -> next);
        return root;
    }
};
//second edition
class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!head)return NULL;
		ListNode *p1 = head,*p2 = head,*prev = NULL;
		while(p2 && p2-> next){prev = p1;p1 = p1 -> next;p2 = p2 -> next -> next;}
		TreeNode *root = new TreeNode(p1 -> val);
		root -> right = sortedListToBST(p1 -> next);
		if(prev){
			prev -> next = NULL;
			root -> left = sortedListToBST(head);
		}
		return root;
	}
};
//简化每次的遍历中点：只一次遍历链表，合理利用当前的计数值，就可以安排好各个节点分别在树的什么位置，
//实现O(n)的时间复杂度。从下往上建立树
BinaryTree* sortedListToBST(ListNode *& list, int start, int end) {
	if (start > end) return NULL;
	// same as (start+end)/2, avoids overflow
	int mid = start + (end - start) / 2;
	BinaryTree *leftChild = sortedListToBST(list, start, mid-1);
	BinaryTree *parent = new BinaryTree(list->data);
	parent->left = leftChild;
	list = list->next;
	parent->right = sortedListToBST(list, mid+1, end);
	return parent;
}

BinaryTree* sortedListToBST(ListNode *head, int n) {
	return sortedListToBST(head, 0, n-1);
}