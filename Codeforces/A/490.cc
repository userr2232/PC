#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v1, v2, v3;
    for(int i = 1; i <= n; ++i) {
        int tmp;
        cin >> tmp;
        if(tmp == 1) v1.push_back(i);
        else if(tmp == 2) v2.push_back(i);
        else v3.push_back(i);
    }
    int teams = min(v1.size(), min(v2.size(), v3.size()));
    cout << teams << endl;
    for(int i = 0; i < teams; ++i) {
        cout << v1[i] << " " << v2[i] << " " << v3[i] << endl;
    }

}