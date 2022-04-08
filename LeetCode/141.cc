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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode *slow{head}, *fast{head->next};
        while(fast != nullptr && fast != slow) {
            slow = slow->next;
            fast = fast->next;
            if(fast != nullptr) fast = fast->next;
        }
        if(fast == slow) return true;
        return false;
    }
};