#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define min(a,b,c) min(a, min(b, c))
using namespace std;
const int N = 1e3+10;
int dp[N][N];
string s1, s2;

int edit_distance(int i, int j) {
    if(i == 0) return j;
    if(j == 0) return i;
    int& ans = dp[i][j];
    if(ans != -1) return ans;
    if(s1[i-1] == s2[j-1]) return ans = edit_distance(i-1, j-1);
    return ans = 1 + min(edit_distance(i, j-1), edit_distance(i-1, j), edit_distance(i-1, j-1));
}

int main() {
    cin >> s1 >> s2;
    memset(dp, -1, sizeof dp);
    cout << edit_distance(s1.length(), s2.length());
}