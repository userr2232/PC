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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head{nullptr}, *current{nullptr};
        while(true) {
            int selected{-1};
            for(int i = 0; i < lists.size(); ++i) if(lists[i] != nullptr) {
                if(selected == -1 || lists[selected]->val > lists[i]->val) selected = i;
            }
            if(selected == -1) break;
            if(current == nullptr) 
                head = current = lists[selected];
            else current->next = lists[selected], current = current->next;
            lists[selected] = lists[selected]->next;
        }
        return head;
    }
};