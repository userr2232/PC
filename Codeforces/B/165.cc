#include <iostream>
#include <cmath>

using namespace std;

long calc(long v, long k) {
    int i = 0;
    long tmp = v / pow(k, i++);
    long lines{0};
    while(tmp) {
        lines += tmp;
        tmp = v / pow(k, i++);
    }
    return lines;
}

int main() {
    long n, k;
    cin >> n >> k;
    long low{1}, high{n}, v{(low + high) / 2}, c{calc(v, k)};
    while(low < high) {
        if(c >= n)
            high = v;
        else
            low = v + 1;
        v = (low + high) / 2;
        c = calc(v, k);
    }
    cout << v << endl;
}