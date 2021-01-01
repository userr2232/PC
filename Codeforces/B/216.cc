#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef set<si> ssi;

vvi adjList;
si unvisited;

int dfs(int v, int prev = -1, int length = 0) {
    unvisited.erase(v);
    int sz = adjList[v].size();
    if(sz <= 1) {
        if(sz == 0) return 0;
        if(unvisited.count(adjList[v][0]))
            dfs(adjList[v][0], v, length+1);
        return 0;
    }
    if(prev == -1) {
        int res = dfs(adjList[v][0], v, length+1);
        if(res)
            return res;
        dfs(adjList[v][1], v, length+1);
        return 0;
    }
    if(unvisited.count(adjList[v][1]))
        return dfs(adjList[v][1], v, length+1);
    if(unvisited.count(adjList[v][0]))
        return dfs(adjList[v][0], v, length+1);
    return ++length;
}

int main() {
    int n, m;
    cin >> n >> m;
    adjList.resize(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        unvisited.insert(a);
        unvisited.insert(b);
        adjList[b].push_back(a);
        adjList[a].push_back(b);
    }
    int count{0};
    while(unvisited.size()) {
        int s = *unvisited.begin();
        if(dfs(s) & 1) {
            count++;
        }
    }
    if((n - count) & 1)
        ++count;
    cout << count << endl;
}