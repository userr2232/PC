#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void print_LIS(int i, vector<int> const& A, vector<int> const& p) {
    if(p[i] != -1) print_LIS(p[i], A, p);
    cout << (p[i] == -1 ? "" : " ") << A[i];
}

void LIS(vector<int> const& A) {
    const int n = A.size();
    vector<int> L(n), L_id(n), p(n);
    int lis_length{0}, lis_end{0};
    for(int i = 0; i < n; ++i) {
        auto pos = distance(L.begin(), lower_bound(L.begin(), L.begin()+lis_length, A[i]));
        L[pos] = A[i];
        L_id[pos] = i;
        p[i] = pos ? L_id[pos-1] : -1;
        if(pos == lis_length) lis_length++, lis_end = i;
    }
    print_LIS(lis_end, A, p);
}

int main() {
    int n; cin >> n;
    vector<int> A(n);
    for(auto&& e : A) cin >> e;
    LIS(A);
}