#include <iostream>
#include <iomanip>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int STEP, MOD;
    while(cin >> STEP && cin >> MOD) {
        cout << setw(10) << STEP << setw(10) << MOD << string(4, ' ');
        if(gcd(STEP, MOD) == 1)
            cout << "Good Choice" << endl << endl;
        else
            cout << "Bad Choice" << endl << endl;
    }
}