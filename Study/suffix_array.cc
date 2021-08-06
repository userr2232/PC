// O(n^2logn)

#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
#define MAX_N 1010
string T;
int SA[MAX_N];

bool cmp(int a, int b) { return T.substr(a) < T.substr(b); }

int main() {
    cin >> T;
    int n = T.length();
    for(int i = 0; i < n; ++i) SA[i] = i;
    sort(SA, SA+n, cmp);
    for(int i = 0; i < n; ++i) cout << SA[i] << "\t" << T.substr(SA[i]) << endl;
}