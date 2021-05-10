#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str; cin >> str;
    sort(str.begin(), str.end());
    stringstream buffer;
    int count{0};
    do {
        count++;
        buffer << str << "\n";
    } while(next_permutation(str.begin(), str.end()));
    cout << count << "\n" << buffer.str();
    return 0;
}