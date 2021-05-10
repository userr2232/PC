#include <iostream>
#include <vector>
#define PB(a) push_back(a)
using namespace std;
typedef vector<int> vi;

void print(const vi& v) {
    cout << v.size() << endl;
    for(auto i : v) cout << i << " ";
    cout << endl;
}

int main() {
    int n; cin >> n;
    long long sum = 1LL * n * (n+1) / 2;
    if(sum & 1) {
        cout << "NO" << endl;
        return 0;
    }
    sum /= 2; n++;
    vi v1, v2;
    while(--n) {
        if(sum - n >= 0)
            sum -= n, v1.PB(n);
        else 
            v2.PB(n);
    }
    cout << "YES" << endl;
    print(v1); print(v2);
    return 0;
}