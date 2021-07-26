#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <set>
using namespace std;
string s, t;
set<string> explored;
map<string,string> p;

vector<string> neighbors(string x) {
    vector<string> ans;
    string tmp;
    if(x[0] != '9') tmp = x, tmp[0] = tmp[0]+1, ans.push_back(tmp);
    if(x[3] != '1') tmp = x, tmp[3] = tmp[3]-1, ans.push_back(tmp);
    ans.push_back(string{x[1], x[2], x[3], x[0]});
    ans.push_back(string{x[3], x[0], x[1], x[2]});
    return ans;
}

void bfs() {
    queue<string> q;
    q.push(s);
    explored.insert(s);
    while(!q.empty()) {
        string current = q.front(); q.pop();
        auto ns = neighbors(current);
        for(auto n : ns) {
            if(explored.count(n) == 0) {
                p[n] = current;
                if(n == t) return;
                q.push(n);
                explored.insert(n);
            }
        }
    }
}

void print(string x) {
    if(p[x] == "") { cout << x << endl; return; }
    print(p[x]);
    cout << x << endl;
}

int main() {
    cin >> s >> t;
    bfs();
    print(t);
}