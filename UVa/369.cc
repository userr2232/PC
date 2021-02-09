#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> memo(101, vector<long long>(101, -1));

long long C(long long n, long long k) {
    if(n == k || k == 0) return 1;
    if(memo[n][k] != -1) return memo[n][k];
    memo[n][k] = C(n - 1, k - 1) + C(n - 1, k);
    return memo[n][k];
}

int main() {
    long long N, M;
    while(cin >> N >> M, N || M)
        cout << N << " things taken " << M << " at a time is " << C(N, M) << " exactly." << endl;
}