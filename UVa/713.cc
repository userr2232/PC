#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string trim(string a) {
    string res = "";
    int i = 0;
    while(a[i] == '0') ++i;
    return a.substr(i);
}

string reverse_add(string a, string b) {
    bool carry = false;
    int la{static_cast<int>(a.length())}, lb{static_cast<int>(b.length())};
    int l = max(la, lb);
    string res = "";
    for(int i = 0; i <= l; ++i) {
        int s = 0;
        if(carry) {
            ++s;
            carry = false;
        }
        if(i < la) s += a[i] - '0';
        if(i < lb) s += b[i] - '0';
        if(s > 9) carry = true;
        res += to_string(s % 10);
    }
    if(res[res.length() - 1] == '0') return trim(res.substr(0, res.length() - 1));
    return trim(res);
}

int main() {
    int N;
    cin >> N;
    while(N--) {
        string a, b;
        cin >> a >> b;
        a = trim(a);
        b = trim(b);
        cout << reverse_add(a, b) << endl;
    }
}