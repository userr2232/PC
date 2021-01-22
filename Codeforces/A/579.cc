#include <iostream>

using namespace std;

int main() {
    int N, count{0};
    cin >> N;
    while(N) {
        if(N & 1)
            count++;
        N >>= 1;
    }
    cout << count << endl;
}