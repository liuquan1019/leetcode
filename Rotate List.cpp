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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || head -> next == NULL)return head;
        ListNode *p = head;
        int num = 1;
        while(p -> next){
            p = p -> next;
            num++;
        }
        k %= num;
        if(k == 0)return head;
        ListNode *q = head;
        int i = num - k - 1;
        while(i > 0){
            q = q -> next;
            i--;
        }
        p -> next = head;
        head = q -> next;
        q -> next = NULL;
        return head;
    }
};