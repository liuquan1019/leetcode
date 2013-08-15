/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//经验：原地倒转链表需要三个指针
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(k <= 1 || !head)return head;
        ListNode *pb = head, *p = head, *pe = head,*q = head;
        ListNode *t1 = head, *t2 = head, *t3 = head;
        int cnt;
        bool first = true;
        
        while(p){
            pb = p;
            cnt = 1;
            while(p -> next && cnt < k){p = p -> next;cnt++;}
            if(cnt == k){
                if(first)head = p;
                else pe -> next = p;
                first = false;
                pe = pb;
                q = p;
                p = p -> next;
                //reverse without p
                if(pb -> next == q)q -> next = pb;
                else if(pb -> next -> next == p){
                    t1 = pb -> next;
                    q -> next = t1;
                    t1 -> next = pb;
                }
                else{
                    t1 = pb;
                    t2 = pb -> next;
                    t3 = pb -> next -> next;
                    while(true){
                        t2 -> next = t1;
                        if(t3 == q)break;
                        t1 = t2;
                        t2 = t3;
                        t3 = t3 -> next;
                    }
                    t3 -> next = t2;
                }
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
//second edition
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(k < 2 || !head)return head;
        ListNode *start = head, *end = head, *p = head,*q = head;
        bool first = true,notRotate = false;
        while(p){
            int n = k - 1;
            start = p;
            while(n > 0 && p){
                p = p -> next;
                n--;
            }
            if(!p){if(q != head)q -> next = start;notRotate = true;break;}
            end = p;
            p = p -> next;
            if(first){head = end;first = false;}
            else q -> next = end;
            q = start;
            reverse(start,end);
        }
        if(q != head && !notRotate)q -> next = NULL;
        return head;
    }
    void reverse(ListNode *start,ListNode *end){
        if(start -> next == end)end -> next = start;
        else{
            ListNode *kk = start,*m = kk -> next, *n = m -> next;
            while(true){
                m -> next = kk;
                if(m == end)break;
                kk = m;m = n;n = n -> next;
            }
        }
    }
};

//third edition
class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!head || !head -> next || k <= 1)return head;
		ListNode *p = head,*q = NULL,*r = NULL,*before = NULL,*after = head;
		head = NULL;
		while(true){
			int cnt = k - 1;
			while(cnt > 0 && after){after = after -> next;cnt--;}
			if(cnt > 0 || !after){
				if(!before)head = p;
				else before -> next = p;
				break;
			}
			if(!head)head = after;
			else before -> next = after;
			after = after -> next;
			before = p;
			q = p -> next;r = q;
			while(true){
				r = r -> next;
				q -> next = p;
				if(r == after)break;
				p = q;
				q = r;
			}
			p = after;
		}
		return head;
	}
};