#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<short> strip(vector<short> v) {
    long long n = (long long)v.size();
    long long start{0}, end{n-1};
    while(v[start] == 0) ++start;
    while(v[end] == 0) --end;
    vector<short> res;
    for(long long i = start; i <= end; ++i) {
        res.push_back(v[i]);
    }
    return res;
}

int main() {
    long long n;
    cin >> n;
    vector<short> v(n);
    for(long long i = 0; i < n; ++i) cin >> v[i];
    vector<long long> zeros;
    long long z_num = 0;
    v = strip(v);
    for(long long i = 0; i < v.size(); ++i) {
        if(v[i] == 0) ++z_num;
        else {
            zeros.push_back(z_num);
            z_num = 0;
        }
    }
    long long answer{1};
    for(long long z : zeros) answer *= z + 1;
    if(zeros.size())
        cout << answer << endl;
    else cout << 0 << endl;
    return 0;
}