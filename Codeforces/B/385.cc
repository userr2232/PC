#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int n{(int)str.length()}, answer{0};
    for(int i = 0; i < n - 3; ++i) {
        auto sub = str.substr(i);
        int pos = sub.find("bear");
        if(pos == string::npos) break;
        answer += sub.length() - pos - 4 + 1;
    }
    cout << answer << endl;
    return 0;
}