#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#define UNVISITED -1
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;

int V, n, m, dfsNumberCounter, SCC;
string horizontal, vertical;
vi dfs_num, dfs_low;
vector<bool> visited;
stack<int> st;

int get_index(int row, int col) {
    return row * m + col;
}

pair<int,int> get_rowcol(int idx) {
    return {idx / m, idx % m};
}

vi neighbors(int u) {
    vi ans;
    auto [row, col] = get_rowcol(u);
    int dx = horizontal[row] == '>' ? 1 : -1;
    int dy = vertical[col] == '^' ? -1 : 1;
    int new_row = row + dy;
    int new_col = col + dx;
    if(new_row >= 0 && new_row < n) ans.emplace_back(get_index(new_row, col));
    if(new_col >= 0 && new_col < m) ans.emplace_back(get_index(row, new_col));
    return ans;
}

void tarjanSCC(int u) {
    dfs_num[u] = dfs_low[u] = ++dfsNumberCounter;
    visited[u] = true;
    st.emplace(u);
    for(auto v : neighbors(u)) {
        if(dfs_num[v] == UNVISITED) tarjanSCC(v);
        if(visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]) {
        ++SCC;
        while(true) {
            int v = st.top();
            st.pop();
            visited[v] = false;
            if(u == v) break;
        }
    }
}

int main() {
    cin >> n >> m;
    V = n * m;
    dfs_num.assign(V, UNVISITED);
    dfs_low.assign(V, -1);
    visited.assign(V, false);
    cin >> horizontal >> vertical;
    FOR(u,0,V-1) if(dfs_num[u] == UNVISITED) tarjanSCC(0);
    cout << (SCC == 1 ? "YES" : "NO") << endl;
}