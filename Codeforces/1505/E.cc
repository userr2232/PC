#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> M(H);
    for(int i = 0; i < H; ++i)
        cin >> M[i];
    int r{0}, d{0};
    pair<int, int> pos = {0, 0};
    bool b = true;
    while(pos.first < H && pos.second < W) {
        auto [row, col] = pos;
        if(M[row][col] == '*') ++r;
        if(b)
            pos.first += 1;
        else
            pos.second += 1;
        b = !b;
    }
    cout << r << endl;
}