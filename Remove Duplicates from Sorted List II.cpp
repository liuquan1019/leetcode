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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || head -> next == NULL)return head;
        ListNode *p = head,*q = head,*pre = head;
        while(p){
            if(p -> next == NULL){
                if(pre -> val == p -> val || p == head)return NULL;
                else break;
            }
            else{
                if(p -> val != p -> next -> val && (p == head ||p -> val != pre -> val))break;
                pre = p;
                p = p -> next;
            }
        }
        head = p;
        if(head -> next == NULL)return head;
        pre = head;
        p = head -> next;
        while(p){
            if(p -> next == NULL){
                if(p -> val != q -> val)pre -> next = p;
                else if(p != pre -> next)pre -> next = NULL;
                break;
                
            }
            if(p -> next -> val != p -> val && p -> val != q -> val){
                pre -> next = p;
                pre = p;
                p = p -> next;
                continue;
            }
            else{
                q = p;
                p = p -> next;
            }
        }
        
        return head;
    }
};
//简单做法（头结点前加一个结点这样避免单独寻找新的头结点）
ListNode sent = new ListNode(0); //Sentinel to guard against the changed head node
sent.next = head;

ListNode cur = head, prev = sent;
while (cur != null) {
	boolean dup = false;
	while (cur.next != null && cur.next.val == cur.val) {
		dup = true;
		cur = cur.next;
	}

	if (dup) {
		prev.next = cur.next;
		cur = cur.next;
	}
	else {
		prev = cur;
		cur = cur.next;
	}
}
return sent.next;

//second edition
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head || !head -> next)return head;
        ListNode *b = head,*p = head,*q = head -> next;
        bool first = true;
        while(p){
            if(q && q -> val == p -> val){
                while(p -> next && p -> val == p -> next -> val)p = p -> next;
                if(!p -> next){
                    if(first)head = NULL;
                    else b -> next = NULL;
                    break;
                }
                p = p -> next;
                q = p -> next;
            }
            else{
                if(first){head = p;first = false;b = head;}
                else{
                    b -> next = p;
                    b = p;
                }
                p = p -> next;
                if(!p)break;
                q = q -> next;
            }
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
		ListNode *p = head,*prev = NULL;
		head = NULL;
		bool appear = false;
		while(p -> next){
			if(p -> val == p -> next -> val)appear = true;
			else if(appear)appear = false;
			else{
				if(!head){head = p;prev = p;}
				else {prev -> next = p;prev = prev -> next;}
			}
			p = p -> next;
		}
		if(!appear){
			if(!head)head = p;
			else prev -> next = p;
		}
		else if(prev)prev -> next = NULL;
		return head;
	}
};
