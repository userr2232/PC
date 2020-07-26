#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 1;
    string magnet;
    cin >> magnet;
    char prev = magnet[1];
    n--;
    while(n--) {
        cin >> magnet;
        if(magnet[0] == prev) {
            count++;
            prev = magnet[1];
        }
    }
    cout << count << endl;
}