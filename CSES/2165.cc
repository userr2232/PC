#include <iostream>

using namespace std;

void hanoi(int i, int from, int to, int aux) {
    if(i == 1) { cout << from << " " << to << "\n"; return; }
    hanoi(i-1, from, aux, to);
    cout << from << " " << to << "\n";
    hanoi(i-1, aux, to, from);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    cout << (1 << n) - 1  << "\n";
    hanoi(n, 1, 3, 2);
    return 0;
}