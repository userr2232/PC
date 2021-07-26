#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;

vector<int> permutation;
vector<bool> taken;
int n;

void search() {
    if(permutation.size() == n) {
        for(auto e : permutation) cout << e << " ";
        cout << "\n";
        return;
    }
    FOR(i,1,n) {
        if(taken[i]) continue;
        taken[i] = true;
        permutation.push_back(i);
        search();
        taken[i] = false;
        permutation.pop_back();
    }
}

int main() {
    cin >> n;
    taken.assign(n+1, false);
    search();
}