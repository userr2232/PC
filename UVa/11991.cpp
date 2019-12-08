#include<vector>
#include<iostream>

using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m) {
        vector<vector<int> > ocurrences(1000000,vector<int>());
        for(int i = 0; i < n; ++i) {
            int element;
            cin >> element;
            ocurrences[element].push_back(i+1);
        }
        for(int i = 0; i < m; ++i) {
            int k, v;
            cin >> k >> v;
            if(--k < ocurrences[v].size())
                cout << ocurrences[v][k] << endl;
            else cout << 0 << endl;
        }
    }

    return 0;
}