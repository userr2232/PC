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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tail{head}, *previous{nullptr}, *current{head};
        for(int i = 0; i < n; ++i) tail = tail->next;
        while(tail) {
            tail = tail->next;
            previous = current;
            current = current->next;
        }
        if(previous == nullptr) {
            auto next = current->next;
            delete current;
            return next;
        }
        previous->next = current->next;
        delete current;
        current = nullptr;
        return head;
    }
};