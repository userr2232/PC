#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

vi subset;
int n;

void subsets(int i = 1) {
    if(i == n+1) {
        for(auto e: subset) cout << e << " ";
        cout << "\n";
        return;
    }
    subset.push_back(i);
    subsets(i+1);
    subset.pop_back();
    subsets(i+1);
}

int main() {
    cin >> n; subsets();
}