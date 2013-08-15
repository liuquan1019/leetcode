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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(l1 == NULL)return l2;
        if(l2 == NULL)return l1;
        ListNode *head = l1,*p1 = l1,*p2 = l2;
        if(l1 -> val > l2 -> val){head = l2;p2 = p2 -> next;}
        else p1 = p1 -> next;
        ListNode *p = head;
        while(p1 && p2){
            if(p1 -> val <= p2 -> val){
                p -> next = p1;
                p = p1;
                p1 = p1 -> next;
            }
            else{
                p -> next = p2;
                p = p2;
                p2 = p2 -> next;
            }
        }
        if(p1) p -> next = p1;
        else if(p2) p -> next = p2; 
        return head;
    }
};
//second edition
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode *head = NULL,*p = NULL,*temp = NULL;
        bool first = true;
        while(l1 && l2){
            if(l1 -> val <= l2 -> val){temp = l1;l1 = l1 -> next;}
            else{temp = l2;l2 = l2 -> next;}
            if(first){head = temp;p = head;first = false;}
            else{p -> next = temp;p = p -> next;}
        }
        if(l1)p -> next = l1;
        else if(l2)p -> next = l2;
        return head;
    }
};