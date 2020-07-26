#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    vector<bool> up(n), down(n), left(n), right(n);
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v[i] = {x,y};
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i != j) {
                if(v[j].first > v[i].first && v[j].second == v[i].second)
                    right[i] = true;
                if(v[j].first < v[i].first && v[j].second == v[i].second)
                    left[i] = true;
                if(v[j].first == v[i].first && v[j].second < v[i].second)
                    down[i] = true;
                if(v[j].first == v[i].first && v[j].second > v[i].second)
                    up[i] = true;
            }
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(up[i] && down[i] && right[i] && left[i])
            count++;
    }
    cout << count << endl;
    return 0;
}