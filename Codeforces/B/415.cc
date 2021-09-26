#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;

int main() {
    long long n, a, b; cin >> n >> a >> b;
    FOR(i,1,n) {
        long long x; cin >> x;
        long long y = x;
        long long original = x * a / b;
        for(int k = x; k >= 1; k /= 2)
            while(x-k >= 0 && original == (x-k)*a/b) x -= k;
        cout << y-x << " ";
    }
}