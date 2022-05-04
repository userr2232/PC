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
    ListNode* reverseList(ListNode* head) {
        ListNode *current{head}, *prev{nullptr};
        while(current != nullptr) {
            auto next = current->next;
            current->next = prev;
            prev = current, current = next;
        }
        return prev;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prevGroupLast{nullptr}, *groupHead{head}, *newHead{nullptr};
        while(groupHead) {
            int i{1};
            ListNode *groupNext{groupHead->next}, *groupLast{groupHead};
            while(i < k && groupNext)
                ++i, groupLast = groupNext, groupNext = groupNext->next;
            groupLast->next = nullptr;
            auto newGroupHead = reverseList(groupHead);
            if(prevGroupLast)
                prevGroupLast->next = newGroupHead;
            if(newHead == nullptr)
                newHead = newGroupHead;
            prevGroupLast = groupHead, groupHead = groupNext;
        }
        return newHead;
    }
};