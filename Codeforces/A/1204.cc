#include <iostream>
 
using namespace std;
 
int main() {
    string t_str;
    cin >> t_str;
    int l = t_str.length() - 1;
    string x = string((t_str.length()-1)/2*2,'0');
    t_str.erase(0,1);
    cout << l/2 + (x == t_str ? 0 : 1);
    return 0;
}