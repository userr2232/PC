#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i = 0 ; i < n; ++i) {
        long long tmp;
        cin >> tmp;
        v[i] = tmp;
    }
    int start(0), end(0);
    for(int i = 0; i < n - 1; ++i) {
        if(v[i] > v[i + 1])
            end = i + 1;
    }
    for(int i = n - 1; i > 0; --i) {
        if(v[i] < v[i - 1])
            start = i - 1;
    }
    reverse(v.begin() + start, v.begin() + end + 1);
    for(int i = 0; i < n - 1; ++i) {
        if(v[i] > v[i + 1]) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    cout << ++start << " " << ++end << endl;

    return 0;
}