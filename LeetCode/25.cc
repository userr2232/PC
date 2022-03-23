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
    void reverseGroup(ListNode* first, ListNode* last) {
        ListNode *next{nullptr},*current{first}, *prev{nullptr};
        for(; current != nullptr; prev = current, current = next) {
            next = current->next;
            current->next = prev;
            if(current == last) break;
        }
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *current{head};
        int counter{0};
        ListNode *first{nullptr}, *last{nullptr}, *prev_last{nullptr}, *new_head{nullptr};
        while(current != nullptr) {
            if(counter++ == 0) first = current;
            last = current;
            current = current->next;
            if(counter == k) {
                if(new_head == nullptr) new_head = last;
                counter = 0;
                reverseGroup(first, last);
                if(prev_last != nullptr) prev_last->next = last;
                prev_last = first;
                first = nullptr, last = nullptr;
            }
        }
        if(first != nullptr && prev_last != nullptr) prev_last->next = first;
        if(new_head == nullptr) new_head = last;
        return new_head;
    }
};