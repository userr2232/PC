#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

vector<unsigned long> v;

void grayCode(int i) {
    if(i == 1) {
        v.push_back(0);
        v.push_back(1);
        return;
    }
    grayCode(i-1);
    for(int j = v.size()-1; j >= 0; --j)
        v.push_back((1<<(i-1)) + v[j]);
}

void print(unsigned long x, int n) {
    auto s = bitset<16>(x).to_string();
    for(int i = s.length()-n; i < s.length(); ++i) cout << s[i];
    cout << endl;
}

int main() {
    int n; cin >> n;
    grayCode(n);
    for(int i = 0; i < (1<<n); ++i)
        print(v[i], n);
}