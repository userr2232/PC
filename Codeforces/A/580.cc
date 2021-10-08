#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int main() {
    int n; cin >> n;
    int prev{0}, longest{0}, current{0};
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        if(x >= prev) current++;
        else current = 1;
        longest = max(longest, current);
        prev = x;
    }
    cout << longest << endl;
    return 0;
}