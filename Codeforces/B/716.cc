#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> count(26, 0);
    int missing{26}, questions{0};
    if(s.length() < 26) {
        cout << -1 << endl;
        return 0;
    }
    else {
        int i;
        for(i = 0; i < 26; ++i) {
            if(s[i] == '?') ++questions;
            else if(++count[s[i]-'A'] == 1) --missing;
        }
        i--;
        while(missing > questions && i < s.length() - 1) {
            if(s[i-25] == '?') --questions;
            else if(--count[s[i-25]-'A'] == 0) ++missing;
            if(s[i+1] == '?') ++questions;
            else if(++count[s[i+1]-'A'] == 1) --missing;
            i++;
        }
        if(missing == questions) {
            short m = 0;
            for(int j = 0; j < 26; ++j) {
                if(missing <= 0) break;
                if(s[i-j] != '?') continue;
                while(count[m]) m++;
                s[i-j] = m++ +'A';
                missing--;
            }
            for(int j = 0; j < s.length(); ++j) {
                if(s[j] == '?') s[j] = 'A';
            }
            cout << s << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}