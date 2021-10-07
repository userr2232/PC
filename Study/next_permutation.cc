#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void next_permutation(vector<int>& v) {
    auto it = is_sorted_until(rbegin(v), rend(v));
    if(it != rend(v)) swap(*it, *upper_bound(rbegin(v), it, *it));
    reverse(rbegin(v), it);
}

int main() {
    int n; cin >> n;
    vector<int> v(n); for(auto& e: v) cin >> e;
    next_permutation(v);
    for(auto e : v) cout << e << " ";
}
