#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
vector<int> permutation;
vector<bool> taken;
int n;
void search() {
    if(permutation.size() == n) {
        for(int x : permutation) cout << x << " ";
        cout << "\n";
        return;
    }
    FOR(i,0,n-1) {
        if(taken[i]) continue;
        taken[i] = true;
        permutation.push_back(i+1);
        search();
        taken[i] = false;
        permutation.pop_back();
    }
}

int main() {
    cin >> n;
    taken.assign(n, false);
    search();

    return 0;
}