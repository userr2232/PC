#include <iostream>
#include <limits>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int leftdist(std::numeric_limits<int>::max() - 1), count(0);
        bool first = true;
        for(char c : s) {
            leftdist++;
            if(c == '1') {
                if(leftdist < k) count--;
                leftdist = -1;
            }
            else {
                if(leftdist >= k) {
                    count++;
                    leftdist = -1;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}