#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int,int>> v(n, pair<int,int>{});
        for(int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            v[i].first = a;
        }
        for(int i = 0; i < n; ++i) {
            int b;
            cin >> b;
            v[i].second = b;
        }  
        for (int i = 0; i < n-1; i++)      
            for (int j = 0; j < n-1; j++)
                for(int k = 1; k < n-1-j; ++k)
                    if (v[j].first > v[j+k].first && v[j].second != v[j+k].second)  
                        swap(v[j], v[j+k]);  
        bool possible  = true;
        for(int i = 0; i < n - 1; ++i) {
            if(v[i].first > v[i+1].first) {
                possible = false;
                break;
            }
        }
        if(possible)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}