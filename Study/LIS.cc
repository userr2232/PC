//-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4, 99
#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;

vi A, p;

void print_LIS(int i) {
    if(p[i] == -1) { cout << A[i]; return; }
    print_LIS(p[i]);
    cout << " " << A[i];
}

int main() {
    int n; cin >> n;
    A.resize(n);
    for(auto& e : A) cin >> e;
    int k{0}, lis_end{0};
    vi L(n,0), L_id(n,0);
    p.resize(n);
    for(int i = 0; i < n-1; ++i) {
        int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
        L[pos] = A[i];
        L_id[pos] = i;
        p[i] = pos ? L_id[pos-1] : -1;
        if(k == pos) ++k, lis_end = i;
    }
    cout << k << endl;
    print_LIS(lis_end);
    return 0;
}