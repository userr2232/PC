#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int s{-1}, t{-1};
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] != '.' && s == -1)
            s = i + 1;
        if(s != -1 && str[i] != 'R') {
            if(str[i] == 'L') t = i;
            else t = i + 1;
            break;
        }
    }
    cout << s << " " << t << endl;

    return 0;
}