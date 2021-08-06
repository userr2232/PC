#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#define MAX_N 100010
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
int n, k, r;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
string T;

void countingSort(int k) {
    int sum{0}, maxi = max(300, n);
    memset(c, 0, sizeof c);
    FOR(i,0,n-1) c[i+k<n ? RA[i+k] : 0]++;
    FOR(i,0,maxi-1) {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    FOR(i,0,n-1) tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    FOR(i,0,n-1) SA[i] = tempSA[i];
}

void constructSA() {
    FOR(i,0,n-1) RA[i] = T[i];
    FOR(i,0,n-1) SA[i] = i;
    for(int k = 1; k < n; k <<= 1) {
        countingSort(k);
        countingSort(0);
        int r = tempRA[SA[0]] = 0;
        FOR(i,1,n-1) tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        FOR(i,0,n-1) RA[i] = tempRA[i];
        if(RA[SA[n-1]] == n-1) break;
    }
}

int main() {
    cin >> T;
    T += '$';
    n = T.length();
    constructSA();
    FOR(i,0,n-1) cout << SA[i] << " " << T.substr(SA[i]) << endl;
}