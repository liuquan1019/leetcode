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
        if(root -> left != NULL)q.push(root -> left);
        if(root -> right != NULL)q.push(root -> right);
        q.push(NULL);
        while(q.size() != 1){
            while(true){
                TreeLinkNode * node1 = q.front();
                q.pop();
                if(node1 == NULL)break;
                if(node1 -> left != NULL)q.push(node1 -> left);
                if(node1 -> right != NULL)q.push(node1 -> right);
                TreeLinkNode * node2 = q.front();
                if(node2 != NULL)node1 -> next = node2;
            }
            q.push(NULL);
        }
    }
};
//second edition先递归处理右子树！！！否则可能没有父节点还没有可能的next
class Solution {
public:
	void connect(TreeLinkNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!root)return;
		if(!root -> left && !root -> right)return;
		if(root -> left)root -> left -> next = root -> right;
		TreeLinkNode *last = root -> left ?  root -> left : root -> right;
		if(last -> next)last = last -> next;
		TreeLinkNode *tmp = root -> next;
		while(tmp){
			if(tmp -> left){last -> next = tmp -> left;break;}
			if(tmp -> right){last -> next = tmp -> right;break;}
			tmp = tmp -> next;
		}
		connect(root -> right);
		connect(root -> left);
	}
};
/*思路二：利用现成的“队列”宽搜
Yes, the memory we need is already there and given! Remember the LinkTreeNode contains 
the next pointer, the reason we need to store all the elements into a queue using 
additional memory previously is that we need all of them to get all the nodes in next 
level. However, we don’t need to store all the elements now, we already can access all 
the information we need as long as we have the first node in that level. Because we make 
the list, so every level is a linked list, once we get the head, we get the whole thing, 
the while information to get all the nodes in next level. So what we need is just constant
number of pointers to store the head.  We still simulate the process of the level order 
traversal (similar to BFS), starting from the root. Now we have the root, so we can pass 
all the nodes in next level (root’s children) and make the list in that level, and we 
store the head of the next level, then we are gonna make the list of the third level, 
since we have the head of the second level list, by going through (list traversal) the 
second level, we can make the third level, we then store the head of the third level list.
We keep doing so until no nodes are left. Note, at all the time, we only need to keep the 
head of the previous level and the head of the current list of level we are processing.
*/
void connect(TreeLinkNode * n) {
	while (n) {
		TreeLinkNode * next = NULL; // the first node of next level
		TreeLinkNode * prev = NULL; // previous node on the same level
		for (; n; n=n->next) {
			if (!next) next = n->left?n->left:n->right;
			if (n->left) {
				if (prev) prev->next = n->left;
				prev = n->left;
			}
			if (n->right) {
				if (prev) prev->next = n->right;
				prev = n->right;
			}
		}
		n = next; // turn to next level
	}
}