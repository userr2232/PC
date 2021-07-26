#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void next_permutation(string& s) {
    auto it = is_sorted_until(rbegin(s), rend(s));
    if(it != rend(s)) swap(*it, *upper_bound(rbegin(s), it, *it));
    reverse(rbegin(s), it);
}

int main() {
    string s; cin >> s;
    next_permutation(s);
    cout << "next_permutation: " << s << endl;
}