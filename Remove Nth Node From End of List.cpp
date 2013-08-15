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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p = head, *q = head;
        //n++;
        while(n > 0 && p){p = p -> next;n--;}
        if(n == 0 && !p)return head -> next;
        else if(n > 0)return head;
        while(p -> next){p = p -> next;q = q -> next;}
        p = q -> next;
        q -> next = q -> next -> next;
        p -> next = NULL;
        delete p;
        return head;
    }
};
//third edition
class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ListNode *slow = head,*fast = head;
		while(n > 0){fast = fast -> next;n--;}
		if(!fast)return head -> next;
		while(fast -> next){slow = slow -> next;fast = fast -> next;}
		slow -> next = slow -> next -> next;
		return head;
	}
};