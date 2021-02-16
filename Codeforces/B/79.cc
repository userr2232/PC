#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <string>
#include <iterator>

using namespace std;

char get_fruit(int w, vector<int>& Xs) {
    string cycle = "CKG"; 
    auto p = lower_bound(Xs.begin(), Xs.end(), w);
    if(*p == w) return 'W';
    auto d = distance(Xs.begin(), p);
    w -= d + 1;
    if(w % 3 == 0) return cycle[0];
    if(w % 3 == 1) return cycle[1];
    return cycle[2];
}

int main() {
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<int> Xs;
    int a, b;
    for(int i = 0; i < k; ++i) {
        cin >> a >> b;
        Xs.push_back(m * (a - 1) + b);
    }
    sort(Xs.begin(), Xs.end());
    for(int i = 0; i < t; ++i) {
        cin >> a >> b;
        auto x = get_fruit(m * (a - 1) + b, Xs);
        switch (x) {
            case 'W':
                cout << "Waste";
                break;
            case 'G':
                cout << "Grapes";
                break;
            case 'C':
                cout << "Carrots";
                break;
            case 'K':
                cout << "Kiwis";
                break;
        }
        cout << endl;
    }
}
