#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<string> v(n);
        pair<int,int> a = {0, 0}, b = {0, 0};
        bool ab{false}, bb{false};
        for(int j = 0; j < n; ++j) {
            cin >> v[j];
            for(int k = 0; k < n; ++k) {
                if(v[j][k] == '*') {
                    if(!ab) {
                        ab = true;
                        a = {j, k};
                    }
                    else {
                        bb = true;
                        b = {j, k};
                    }
                }
            }
        }
        auto [ar, ac] = a;
        auto [br, bc] = b;
        if(ar != br && ac != bc) {
            v[ar][bc] = '*';
            v[br][ac] = '*';
        }
        else if(ar == br) {
            if(ar < n - 1) {
                v[ar+1][ac] = '*';
                v[br+1][bc] = '*';
            }
            else {
                v[ar-1][ac] = '*';
                v[br-1][bc] = '*';
            }
        }
        else {
            if(ac < n - 1) {
                v[ar][ac+1] = '*';
                v[br][bc+1] = '*';
            }
            else {
                v[ar][ac-1] = '*';
                v[br][bc-1] = '*';
            }
        }
        for(int j = 0; j < n; ++j) {
            cout << v[j] << endl;
        }
    }


    return 0;
}