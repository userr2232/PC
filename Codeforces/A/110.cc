#include <iostream>

using namespace std;

bool isLucky(long long x) {
    if(x == 0)
        return false;
    while(x) {
        if(x % 10 != 4 && x % 10 != 7) 
            return false;
        x /= 10;
    }
    return true;
}

int main () {
    long long x;
    cin >> x;
    int count = 0;
    while(x) {
        int tmp = x % 10;
        if(tmp == 4 || tmp == 7) {
            count++;
        }
        x /= 10;
    }
    cout << (isLucky(count) ? "YES" : "NO") << endl;

    return 0;
}