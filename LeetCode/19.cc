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
        ListNode *front{head}, *current{head}, *prev{nullptr};
        for(int i = 0; i < n; ++i) front = front->next;
        while(front) {
            prev = current;
            front = front->next;
            current = current->next;
        }
        if(prev == nullptr) head = current->next;
        else prev->next = current->next;
        delete current;
        current = nullptr;
        return head;
    }
};