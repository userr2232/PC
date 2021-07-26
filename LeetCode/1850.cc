#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void next_permutation(string& s) {
        auto it = is_sorted_until(rbegin(s), rend(s));
        if(it != rend(s)) swap(*it, *upper_bound(rbegin(s), it, *it));
        reverse(rbegin(s), it);
    }

    int getMinSwaps(string num, int k) {
        string k_str = num;
        while(k--) next_permutation(k_str);
        int ans{0};
        for(int i = 0; i < num.length(); ++i) {
            if(k_str[i] != num[i]) {
                int pos = num.find(num[i], i);
                while(pos > i) {
                    swap(num[pos], num[pos-1]);
                    pos--;
                    ans++;
                }
            }
        }
        return ans;
    }
};