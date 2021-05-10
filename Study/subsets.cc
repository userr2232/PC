#include <iostream>
#include <vector>
using namespace std;
vector<int> subset;
int n;
void search(int i = 1) {
    if(i == n+1) {
        for(int x : subset) cout << x << " ";
        cout << "\n";
        return;
    }
    subset.push_back(i);
    search(i+1);
    subset.pop_back();
    search(i+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    search();
    return 0;
}