#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> host(n), guest(n);
    for(int i = 0; i < n; ++i) {
        cin >> host[i] >> guest[i];
    }
    int count = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == j) continue;
            if(host[i] == guest[j]) count++;
        }
    }
    cout << count << endl;

    return 0;
}