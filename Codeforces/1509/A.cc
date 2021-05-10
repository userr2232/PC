#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> heights(n);
    int odds{0}, evens{0};
    for(int i = 0; i < n; ++i) {
        cin >> heights[i];
        if(heights[i] % 2) odds++;
        else evens++;
    }
    for(int i = 0; i < n; ++i) {
        if(heights[i]%2 == odds > evens) cout << heights[i] << " ";
    }
    for(int i = 0; i < n; ++i) {
        if(heights[i]%2 == odds <= evens) cout << heights[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--)
    solve();
}