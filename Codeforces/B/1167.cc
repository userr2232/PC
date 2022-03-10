#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v = {4, 8, 15, 16, 23, 42};

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int num;
    cin >> num;
    return num;
}

void find_and_swap(int num, int pos) {
    for(auto& e : v) {
        if(e == num) {
            swap(e, v[pos]);
            break;
        }
    }
}

int main() {
    for(int i = 0; i < 2; ++i) {
        int ans = query(i+1, i+1);
        find_and_swap(sqrt(ans), i);
    }
    int q3 = query(3, 4);
    int a, b, c{-1}, d{-1};
    for(int i = 2; i < 6; ++i) for(int j = 2; j < 6; ++j) if(i != j) {
        if(v[i] * v[j] == q3) {
            a = i, b = j;
            swap(v[a], v[2]);
            swap(v[b], v[3]);
            for(int k = 3; k < 6; ++k) if(k != i && k != j) {
                if(c == -1) c = k, swap(v[3], v[k]);
                else if(d == -1) d = k, swap(v[4], v[k]);
            }
        }
    }
    int q4 = query(4, 5);
    for(int i = 2; i <= 3; ++i) for(int j = 4; j <= 5; ++j) {
        if(v[i] * v[j] == q4) {
            swap(v[3], v[i]);
            swap(v[4], v[j]);
            cout << "!";
            for(auto& e: v) {
                cout << " " << e;
            }
            cout << endl;
            return 0;
        }
    }
    return 0;
}