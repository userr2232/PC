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
    string add(const string& str1, const string& str2) {
        int i{0}, j{0};
        const int m = str1.length(), n = str2.length();
        bool carry{false};
        string ans;
        while(i < m || j < n) {
            int sum;
            if(i < m && j < n)
                sum = str1[i]-'0' + str2[j]-'0', i++, j++;
            else if(i < m)
                sum = str1[i]-'0', i++;
            else
                sum = str2[j]-'0', j++;
            sum += static_cast<int>(carry);
            carry = sum >= 10;
            sum = sum >= 10 ? sum - 10 : sum;
            ans += static_cast<char>('0'+sum);
        }
        if(carry) ans += '1';
        return ans;
    }
    
    ListNode* build(const string& str) {
        ListNode *head{nullptr}, *current{nullptr};
        for(auto c : str) {
            auto node = new ListNode(c-'0');
            if(current == nullptr)
                head = current = node;
            else
                current = current->next = node;
        }
        return head;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string str1, str2;
        while(l1 != nullptr)
            str1 += static_cast<char>('0' + l1->val), l1 = l1->next;
        while(l2 != nullptr)
            str2 += static_cast<char>('0' + l2->val), l2 = l2->next;
        auto str = add(str1, str2);
        return build(str);
    }
};