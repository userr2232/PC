#include <iostream>
#include <vector>

using namespace std;

long long f(int count) {
    long long fac{1};
    while(count) fac *= count--;
    return fac;
}

int main() {
    int n; cin >> n;
    string str;
    vector<int> counter(26);
    while(n--) {
        cin >> str;
        counter[str[0]-'a']++;
    }
    long long answer{0};
    for(auto count : counter) {
        auto c1 = count / 2;
        auto c2 = ++count / 2;
        if(c1 > 0) answer += (c1 * (c1-1)) / 2;
        if(c2 > 0) answer += (c2 * (c2-1)) / 2;
    }
    cout << answer << endl;
    return 0;
}