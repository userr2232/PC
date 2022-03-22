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
    ListNode* min(vector<ListNode*>& lists) {
        ListNode* ans{nullptr};
        int idx{-1};
        for(int i = 0; i < lists.size(); ++i) if(auto node = lists[i]; node != nullptr) {
            if(ans == nullptr || ans->val > node->val) ans = node, idx = i;
        }
        if(idx != -1) lists[idx] = lists[idx]->next;
        return ans;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* head = min(lists);
        ListNode* current = head;
        for(auto node = min(lists); node != nullptr; node = min(lists)) {
            current->next = node;
            current = node;
        }
        if(current) current->next = nullptr;
        return head;
    }
};