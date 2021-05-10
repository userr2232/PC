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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    A = {-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4, 99};
    int n = A.size(), k{0}, lis_end{0};
    vi L(n, 0), L_id(n, 0);
    p.assign(n,-1);
    FOR(i,0,n-1) {
        int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
        L[pos] = A[i];
        L_id[pos] = i;
        p[i] = pos ? L_id[pos-1] : -1;
        if(pos == k) k++, lis_end = i;
    }
    cout << k << "\n";
    print_LIS(lis_end);
    return 0;
}