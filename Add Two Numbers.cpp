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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(l1 == NULL)return l2;
        if(l2 == NULL)return l1;
        int cnt = 0,temp;
        ListNode *p = l1;
        while(p -> next && l2 -> next){
            temp = p -> val + l2 -> val + cnt;
            if(temp > 9){p -> val = temp - 10;cnt = 1;}
            else{p -> val = temp;cnt = 0;}
            p = p -> next;
            l2 = l2 -> next;
        }
        temp = p -> val + l2 -> val + cnt;
        if(temp > 9){p -> val = temp - 10;cnt = 1;}
        else{p -> val = temp;cnt = 0;}
        if(p -> next || l2 -> next){
            if(p -> next == NULL && l2 -> next)
                p -> next = l2 -> next;
            p = p -> next;
            while(p -> next){
                if(p -> val + cnt > 9){p -> val = 0;cnt = 1;}
                else {p -> val += cnt;cnt = 0;}
                p = p -> next;
            }
            if(p -> val + cnt > 9){p -> val = 0;cnt = 1;}
            else {p -> val += cnt;cnt = 0;}
        }
        if(cnt){
            ListNode * temp = new ListNode(1);
            p -> next = temp;
        }
        return l1;    
    }
};