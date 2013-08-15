/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//可别小看链表问题，大思路好想，但很多细节易考虑不到,可以提前写好各种情况的测试用例
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)return head;
        ListNode *p = head,*q = head;
        while(p){
            if(p -> next == NULL)break;
            q = p;
            while(q -> next){
                q = q -> next;
                if(q -> val != p -> val)break;
            }
            if(q -> val != p -> val){
                p -> next = q;
                p = q;
            }
            else{p -> next = NULL;break;}
        }
        return head;
    }
};
//second edition
class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!head || !head -> next)return head;
		ListNode *p = head,*q = head -> next;
		while(q){
			if(q -> val == p -> val)p -> next = q -> next;
			else p = q;
			q = q -> next;
		}
		return head;
	}
};
//third edition
class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!head)return head;
		ListNode *p = head;
		while(p -> next){
			if(p -> val == p -> next -> val)p -> next = p -> next -> next;
			else p = p -> next;
		}
		return head;
	}
};
