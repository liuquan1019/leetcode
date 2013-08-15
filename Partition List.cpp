/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)return head;
        queue<ListNode *> q1,q2;
        ListNode *p = head;
        while(p!= NULL){
            if(p -> val < x)q1.push(p);
            else q2.push(p);
            p = p -> next;
        }
        if(!q1.empty()){
            head = q1.front();
            q1.pop();
            p = head;
            while(!q1.empty()){
                p -> next = q1.front();
                q1.pop();
                p = p -> next;
            }
        }
        else{
            head = q2.front();
            q2.pop();
            p = head;
        }
        while(!q2.empty()){
                p -> next = q2.front();
                q2.pop();
                p = p -> next;
        }
        p -> next = NULL;
        return head;
    }
};
//second edition:错误百出，在于初始都指向同一位置，若之后未修改它，则对它赋值会改变答案链表中的元素！！！
class Solution {
public:
	ListNode *partition(ListNode *head, int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!head || !head -> next)return head;
		ListNode *p = head,*q1 = head,*q2 =head,*head2 = NULL;
		head = NULL;
		bool first1 = true,first2 = true;
		while(p){
			if(p -> val < x){
				if(first1){head = p;q1 = head;first1 = false;}
				else{q1 -> next = p;q1 = q1 -> next;}
			}
			else{
				if(first2){head2 = p;q2 = head2;first2 = false;}
				else{q2 -> next = p;q2 = q2 -> next;}
			}
			p = p -> next;
		}
		if(head){
			if(head2){q1 -> next = head2;q2 -> next = NULL;}
			return head;}
		return head2;
	}
};
/*法二：
The idea is:   first get the last element and the length of the list (1 while loop)
	Then scan the whole list, if current node value < x, then go to the next node.
		if current node value >=x, then move this node to the end of the list.
	until  meet the length of the original list.
*/