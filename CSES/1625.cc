#include <iostream>
#include <vector>
#include <cstring>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
const int N = 9;
int ans = 0;
bool vis[N][N];
char dir[N][N];
string s;

void search(int i, int j, int k, char& current) {
    bool& v = vis[i][j];
    if(k == 48) {
        if(i == 7 && j == 1) ans++;
        v = false;
        return; 
    }
    char &up = dir[i-1][j], &down = dir[i+1][j], 
            &left = dir[i][j-1], &right = dir[i][j+1];
    if(
        (i == 7 && j == 1) || 
        (
            (current == 'U' || current == 'D') && 
            (left == current || right == current)
        ) ||
        (
            (current == 'R' || current == 'L') && 
            (up == current || down == current)
        )
    ) return;

    v = true;
    if(s[k] == '?' || s[k] == 'L')
        if(j > 1 && !vis[i][j-1])
            left = 'L', search(i, j-1, k+1, left), left = '-';
    if(s[k] == '?' || s[k] == 'U')
        if(i > 1 && !vis[i-1][j])
            up = 'U', search(i-1, j, k+1, up), up = '-';
    if(s[k] == '?' || s[k] == 'D')
        if(i < 7 && !vis[i+1][j])
            down = 'D', search(i+1, j, k+1, down), down = '-';
    if(s[k] == '?' || s[k] == 'R')
        if(j < 7 && !vis[i][j+1])
            right = 'R', search(i, j+1, k+1, right), right = '-';
    v = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    memset(dir, '-', sizeof dir);
    FOR(i,0,7) {
        dir[0][i] = 'L';
        dir[8][i] = 'R';
        dir[i][0] = 'U';
        dir[i][8] = 'U';
    }
    search(1,1,0,dir[1][1]);
    cout << ans << "\n";
    return 0;
}