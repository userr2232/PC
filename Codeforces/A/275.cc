#include <iostream>
#include <vector>

using namespace std;

void switchLights(int i, int j, vector<vector<bool>>& v) {
    if(i >= 3 || i < 0 || j >= 3 || j < 0)
        return;
    v[i][j] = !v[i][j];
}

int main() {
    vector<vector<bool>> v(3, vector<bool>(3, true));
    vector<vector<bool>> s(3, vector<bool>(3, false));
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j) {
            int tmp;
            cin >> tmp;
            s[i][j] = tmp % 2;
        }
    }
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            if(s[i][j]) {
                switchLights(i, j, v);
                switchLights(i - 1, j, v);
                switchLights(i + 1, j, v);
                switchLights(i, j - 1, v);
                switchLights(i, j + 1, v);
            }
    
    for(auto const& row: v) {
        for(auto const& b: row) {
            cout << b;
        }
        cout << endl;
    }
}