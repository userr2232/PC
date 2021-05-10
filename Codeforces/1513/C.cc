// t = int(input())
// while t:
//     t -= 1
//     n, m = map(int, input().strip().split())
//     s = str(n)
//     i = 0
//     while i < m:
//         i += 1
//         s = ''.join(str(int(x) + 1) for x in s)
//     print(len(s) % int(1e9 + 7))

#include <iostream>
#include <string>

using namespace std;

int main() {
    int  t;

    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> v = to_string(n);
        while(m--) {
            string k = "";
            for(int i = 0; i < v.size(); ++i) {
                k += to_string(s[i])
            }
        }
    }



    return 0;
}