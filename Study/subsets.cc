#include <iostream>
#include <vector>
using namespace std;

int n, counter;
vector<int> v;

void subsets(int i = 1) {
    if(i == n+1) {
        cout << ++counter << ": ";
        for(auto e : v) cout << e << " ";
        cout << endl;
        return;
    }
    v.emplace_back(i);
    subsets(i+1);
    v.pop_back();
    subsets(i+1);
}

int main() {
    cin >> n; subsets();
    return 0;
}