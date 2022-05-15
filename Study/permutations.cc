#include <iostream>
#include <vector>

using namespace std;

void permutations(vector<bool>& taken, vector<int>&& v = {}) {
    if(v.size() == taken.size()) {
        for(auto&& e : v) cout << e << " ";
        cout << endl;
        return;
    }
    for(int i = 0; i < taken.size(); ++i) if(!taken[i]) {
        taken[i] = true;
        v.emplace_back(i);
        permutations(taken, forward<vector<int>>(v));
        v.pop_back();
        taken[i] = false;
    }
}

int main() {
    int n; cin >> n;
    vector<bool> taken(n, false);
    permutations(taken);
}