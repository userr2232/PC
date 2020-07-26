#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    char cur = 'a';
    string str;
    cin >> str;
    int cost = 0;
    for(const auto & c : str) {
        if(c > cur) {
            cost += min(c - cur, 'z' - c + cur - 'a' + 1);
        }
        else if(c < cur) {
            cost += min(cur - c, 'z' - cur + c - 'a' + 1);
        }
        cur = c;
    }
    cout << cost << endl;
}