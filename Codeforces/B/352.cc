#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    int n, tmp;
    cin >> n;
    map<int, vector<int>> mp;
    for(int i = 1; i <= n; ++i) {
        cin >> tmp;
        mp[tmp].push_back(i);
    }
    string answer = "";
    int t{0};
    for(auto [key, v] : mp) {
        if(v.size() == 1) {
            ++t;
            answer += to_string(key) + " 0\n";
        }
        else if(v.size() == 2) {
            ++t;
            answer += to_string(key) + " " + to_string(v[1] - v[0]) + "\n";
        }
        else {
            int d = v[1] - v[0];
            bool b = true;
            string str = to_string(key) + " " + to_string(d) + "\n";
            for(int i = 1; i < v.size(); ++i) {
                if(v[i] - v[i-1] != d) {
                    b = false;
                    break;
                }
            }
            if(b) {
                ++t;
                answer += str;
            }
        }
    }
    cout << t << endl;
    cout << answer;

    return 0;
}