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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(lists.empty())return NULL;
        ListNode *head = NULL,*p = NULL;
        int Min,min_i;
        bool first = true;
        while(true){
            Min = INT_MAX;min_i = -1;
            for(int i = 0;i < lists.size();i++){
                if(lists[i] && lists[i] -> val < Min){
                    min_i = i;
                    Min = lists[i] -> val;
                }
            }
            if(min_i == -1)break;
            if(first){head = lists[min_i];first = false;p = head;}
            else {p -> next = lists[min_i];p = p -> next;}
            lists[min_i] = lists[min_i] -> next;
        }
        return head;
    }
};
//正解用堆实现，可利用multiset或者<algorithm>中的make_heap
ListNode *mergeKLists(vector<ListNode *> &lists) {
	vector<ListNode*>::iterator it = lists.begin();
	while(it != lists.end()) {
		if(*it == NULL) lists.erase(it);
		else ++it;
	}
	if(lists.size() < 1) return NULL;

	ListNode *head = NULL, *cur = NULL;
	make_heap(lists.begin(), lists.end(), comp());

	while(lists.size() > 0) {
		if(head == NULL) head = cur = lists[0];
		else cur = cur->next = lists[0];

		pop_heap(lists.begin(), lists.end(), comp());
		int last = lists.size() - 1;
		if(lists[last]->next != NULL) {
			lists[last] = lists[last]->next;
			push_heap(lists.begin(), lists.end(), comp());
		}
		else lists.pop_back();
	}

	return head;
}

class comp {
public:
	bool operator() (const ListNode* l, const ListNode* r) const {
		return (l->val > r->val);
	}
};
//解二:multiset或者priority_queue
class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		multiset<ListNode*, comparator> S;
		for (int i = 0; i < lists.size(); ++i) {
			if (lists[i]) {
				S.insert(lists[i]);
			}
		}

		ListNode* head = 0;
		ListNode* tail = 0;
		while (!S.empty()) {
			ListNode* node = *S.begin();
			S.erase(S.begin());
			if (!head) {
				head = tail = node;
			}
			else {
				tail = tail->next = node;
			}
			if (node->next) {
				S.insert(node->next);
			}
		}

		return head;
	}

	struct comparator: public binary_function<ListNode*, ListNode*, bool> {
		bool operator() (const ListNode* a, const ListNode* b) {
			return a->val < b->val;
		}
	};
};
//third edition
#include<priority_queue>
class Comp{
public:
	bool operator() (ListNode *l1,ListNode *l2){
		return l1 -> val > l2 -> val;
	}
};
class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		priority_queue<ListNode *,vector<ListNode *>,Comp> queue;
		for(int i = 0;i < lists.size();i++)if(lists[i])queue.push(lists[i]);
		ListNode *head = NULL,*p = NULL;
		while(!queue.empty()){
			if(!head)head = p =queue.top();
			else p = p -> next = queue.top();
			if(queue.top() -> next)queue.push(queue.top() -> next);
			queue.pop();
		}
		return head;
	}
};