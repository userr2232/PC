#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a, b;
    vector<int> can_open(n);
    vector<int> to_open(n);
    for(int i = 0; i < n; ++i) {
        cin >> a >> b;
        can_open[i] = b;
        to_open[i] = a;
    }
    int count = 0;
    for(int i = 0; i < n; ++i) {
        bool open = false;
        for(int j = 0; j < n; ++j) {
            if(to_open[i] == can_open[j] && i != j) {
                open = true;
            }
        }
        if(!open) ++count;
    }
    cout << count << endl;
    return 0;
}