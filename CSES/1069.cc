#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;
    int n = str.length();
    int count{1}, answer{0};
    for(int i = 1; i < n; ++i) {
        if(str[i] == str[i-1]) count++;
        else count = 1;
        answer = max(answer, count);
    }
    cout << (answer ? answer : n) << endl;
}