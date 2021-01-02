#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool out = false;
    vector<string> sq;
    set<char> all_set;
    for(int i = 0; i < n && !out; ++i) {
        string tmp;
        cin >> tmp;
        sq.push_back(tmp);
        set<char> tmp_set;
        for(auto c : tmp) {
            tmp_set.insert(c);
            all_set.insert(c);
            if(all_set.size() > 2) {
                cout << "NO" << endl;
                out = true;
                break;
            }
        }
    }
    char main_char = sq[0][0];
    for(int i = 0; i < n && !out; ++i) {
        int sum = 0;
        for(int j = 0; j < n && !out; ++j) {
            if(i == n / 2) {
                if(sq[i][j] == main_char) {
                    if(j != n / 2) {
                        cout << "NO" << endl;
                        out = true;
                        break;
                    }
                }
                else {
                    if(j == n / 2) {
                        cout << "NO" << endl;
                        out = true;
                        break;
                    }
                }
            }
            else {
                if(sq[i][j] == main_char) {
                    sum += j + 1;
                }
            }
        }
        if(i != n/2 && !out && sum != n + 1) {
            cout << "NO" << endl;
            out = true;
            break;
        }
    }
    if(!out)
        cout << "YES" << endl;
}