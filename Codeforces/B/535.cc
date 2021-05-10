#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    string str, binstr; cin >> str;
    int n = str.length();
    for(auto c : str) {
        if(c == '4') binstr += '0';
        else binstr += '1';
    }
    std::bitset<11> b(binstr);
    cout << ((1 << n) - 2) + b.to_ulong() + 1 << endl;
}