#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int i(0), j(n-1), s(0), o(0), k(0);
    while(i <= j) {
        if(v[i] > v[j]) {
            if(k % 2) { 
                o += v[i];
            }
            else {
                s += v[i];
            }
            i++;
        }
        else {
            if(k % 2) {
                o += v[j];
            }
            else {
                s += v[j];
            }
            j--;
        }
        k++;
    }
    cout << s << " " << o << endl;

    return 0;
}