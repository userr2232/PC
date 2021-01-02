#include <iostream>

using namespace std;

int main() {
    int n, a_score{0}, b_score{0};;
    cin >> n;
    string a, b, tmp;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        if(!i) {
            a = tmp;
            ++a_score;
        }
        else {
            if(tmp == a) ++a_score;
            else {
                b = tmp;
                ++b_score;
            }
        }
    }
    cout << ((a_score > b_score) ? a : b) << endl;
}