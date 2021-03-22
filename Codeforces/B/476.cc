#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <utility>

using namespace std;

string a, b;
map<pair<int, int>, double> probs;

double DP(int idx, int val) {
    if(idx == a.length()) {
        if(val != 0) return 0;
        return 1;
    }
    if(probs.count({idx, val})) return probs[{idx, val}];
    double answer;
    if(b[idx] == '+') answer = DP(idx+1, val-1);
    else if(b[idx] == '-') answer = DP(idx+1, val+1);
    else answer = 0.5 * (DP(idx+1, val+1) + DP(idx+1, val-1));
    probs[{idx, val}] = answer;
    return answer;
}

int main() {
    cin >> a >> b;
    int val{0};
    for(auto c : a) {
        if(c == '+') ++val;
        else --val;
    }
    cout << fixed << setprecision(9) << DP(0, val) << endl;
}