#include <iostream>
#include <map>
using namespace std;

map<long long, long long> m;

long long f(long long n) {
    if(m.count(n)) return m[n];
    if(n <= 1) return m[n] = n;
    if(n % 2) return m[n] = f(n/2) + f(n/2+1);
    return m[n] = f(n/2);
}

int main() {
    long long n; cin >> n;
    cout << f(n) << endl;
}