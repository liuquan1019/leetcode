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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head)return head;
        ListNode *pb = head, *p = head, *pe = head,*q = head;
        int cnt;
        bool first = true;
        
        while(p){
            pb = p;
            cnt = 1;
            while(p -> next && cnt < 2){p = p -> next;cnt++;}
            if(cnt == 2){
                if(first)head = p;
                else pe -> next = p;
                first = false;
                pe = pb;
                q = p;
                p = p -> next;
                q -> next = pb;
                pe -> next = NULL;
            }
            else{
               if(first)break;
               pe -> next = pb;
               break;
            }
        }
        return head;
    }
};

//third edition
class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!head || !head -> next)return head;
		ListNode *p = head,*q = NULL,*r = NULL;
		head = NULL;
		while(true){
			r = p -> next -> next;
			p -> next -> next = p;
			if(!q) head = p -> next;
			else q -> next = p -> next;
			q = p;
			if(!r || !r -> next)break;
			p = r;
		}
		q -> next = r;
		return head;
	}
};