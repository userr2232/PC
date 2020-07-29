#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    set<char> s;
    for(int i = 0; i < n; ++i) {
        if(str[i] < 'a') {
            str[i] = str[i] + 'a' - 'A';
        }
        s.insert(str[i]);
    }
    if(s.size() == 26)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}