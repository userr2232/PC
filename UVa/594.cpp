#include <iostream>

using namespace std;

int main() {
    int m;
    while(cin >> m)
        cout << m << " converts to " << ( m << 24 | m >> 8 & 0xff00 | m << 8 & 0xff0000 | m >> 24 & 0xff ) << endl ;

    return 0;
}