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
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto cur : lists) {
            while(cur) {
                pq.push(cur->val);
                cur = cur->next;
            }
        }
        ListNode* head = new ListNode();
        ListNode* cur = head;
        while(!pq.empty()) {
            cur->next = new ListNode(pq.top());
            pq.pop();
            cur = cur->next;
        }
        ListNode* first = head->next;
        delete head;
        return first;
    }
};