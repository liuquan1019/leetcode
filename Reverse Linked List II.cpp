/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//链表问题尤其细心临界情况，比如单节点或只有两个节点或尾节点
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || m == n)return head;
        int i;
        ListNode *p = head;
        for(i = 1;i < m;i++)p = p -> next;
        ListNode *q = p;
        stack<int> s;
        for(;i <= n;i++){
            s.push(q -> val);
            q = q -> next;  
        }
        while(!s.empty()){
            p -> val = s.top();
            s.pop();
            p = p -> next;
        }
        return head;
    }
};
//second edition
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m == n || !head)return head;
        ListNode *p = head, *pb = head,*pe = head,*q = p -> next,*r = q -> next;
        bool first = false;
        m--;n --;
        if(m == 0)first = true;
        else{
            m--;n--;
            while(m > 0){pb = pb -> next;m--;n--;}
            p = pb -> next;
            pe = p;q = p -> next;r = q -> next;
        }
        if(m == n)q -> next = p;
        else{
            while(true){
                q -> next = p;
                n --;
                if(n == 0)break;
                p = q;q = r;r = r -> next;
            }
        }
        if(first)head = q;
        else pb -> next = q;
        pe -> next = r;
        return head;
    }
};
//简化：


ListNode *reverseBetween(ListNode *head, int m, int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	ListNode dummy(0);
	dummy.next = head;
	ListNode *preM, *pre = &dummy;
	for (int i = 1; i <= n; ++i) {
		if (i == m) preM = pre;
		if (i > m && i <= n) {
			pre->next = head->next;
			head->next = preM->next;
			preM->next = head;
			head = pre; // head has been moved, so pre becomes current
		}
		pre = head;
		head = head->next;
	}
	return dummy.next;
}

