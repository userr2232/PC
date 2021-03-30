#include <iostream>
#include <string>
#include <set>

using namespace std;

int process(string str) {
    int first{-1}, second{-1};
    for(int i = 0; i < str.length(); ++i) {
        if(str[i] == 'G') first = i;
        else if(str[i] == 'S') {
            if(first == -1) return -1;
            return i - first - 1;
        }
    }
    return -3;
}

int main() {
    int n, m;
    string str;
    cin >> n >> m;
    set<int> ds;
    for(int i = 0; i < n; ++i) {
        cin >> str;
        auto a = process(str);
        if(a == -1) {
            cout << -1 << endl;
            return 0;
        }
        ds.insert(a);
    }
    cout << ds.size() << endl;
    return 0;
}