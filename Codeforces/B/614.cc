#include <iostream>
#include <string>
using namespace std;

bool isbeautiful(string x) {
    int zeros{0}, ones{0}, other{0};
    for(char c : x) {
        if(c == '0') ++zeros;
        else if(c == '1') ++ones;
        else ++other;
    }
    return ones <= 1 && x.length() == zeros + ones;
}

int main() {
    int n; cin >> n;
    long long length{0};
    bool found{false};
    string beautiful;
    for(int i = 0; i < n; ++i) {
        string x; cin >> x;
        if(x == "0") { cout << 0 << endl; return 0; }
        else if(!found && !isbeautiful(x)) {
            found = true;
            beautiful = x;
        }
        else {
            length += x.size() - 1;
        }
    }
    cout << (beautiful == "" ? "1" : beautiful) << string(length, '0') << endl;
}