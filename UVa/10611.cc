#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

pair<string, string> findTwo(vector<int> &v, deque<int>& vm, int height) {
    auto h = upper_bound(v.begin(), v.end(), height);
    auto l = lower_bound(vm.begin(), vm.end(), -(height - 1));
    return {(l == vm.end() ? "X" : to_string(-(*l))), (h == v.end() ? "X" : to_string(*h))};
}

int main() {
    int N, tmp;
    vector<int> v;
    deque<int> vm;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> tmp;
        v.push_back(tmp);
        vm.push_front(-tmp);
    }
    int Q;
    cin >> Q;
    while(Q--) {
        cin >> tmp;
        auto p = findTwo(v, vm, tmp);
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}