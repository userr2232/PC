/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    void add(ListNode*& l, ListNode*& previous, ListNode*& head) {
        if(head == nullptr) head = previous = l;
        else previous = previous->next = l;
        l = l->next;
    }
    
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode *head{nullptr}, *previous{nullptr};
        while(l1 && l2) {
            if(l1->val < l2->val) add(l1, previous, head);
            else add(l2, previous, head);
        }
        if(l1) add(l1, previous, head);
        if(l2) add(l2, previous, head);
        return head;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        const int n = lists.size();
        int h = 32 - __builtin_clz(n);
        int step{1};
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < n; j += step << 1)
                lists[j] = mergeLists(lists[j], j+step < n ? lists[j+step] : nullptr);
            step <<= 1;
        }
        return lists[0];
    }
};