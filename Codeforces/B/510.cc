#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define UNVISITED -1
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#ifdef DEBUG_BUILD
#  define DEBUG(x) cerr << x
#else
#  define DEBUG(x) do {} while (0)
#endif
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

int n, m;
int dfsNumberCounter;
int edges, vertices;
vector<string> graph;
vector<vi> dfs_num;


bool has_cycle() {
    edges /= 2;
    return edges != vertices - 1 && vertices >= 4;
}

bool valid(int i, int di, int j, int dj) {
    auto [new_i, new_j] = ii(i+di, j+dj);
    return new_i >= 0 && new_i < n && new_j >= 0 && new_j < m;
}

void dfs(int i, int j) {
    char color = graph[i][j];
    dfs_num[i][j] = ++dfsNumberCounter;
    ++vertices;
    FOR(di,-1,1) FOR(dj,-1,1) if(abs(di) != abs(dj) && valid(i, di, j, dj)) {
        auto [new_i, new_j] = ii(i+di, j+dj);
        if(color != graph[new_i][new_j]) continue;
        edges++;
        if(dfs_num[new_i][new_j] == UNVISITED) dfs(new_i, new_j);
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n);
    dfs_num.assign(n, vi(m, UNVISITED));
    FOR(i,0,n-1) cin >> graph[i];
    FOR(i,0,n-1) FOR(j,0,m-1) {
        edges = 0, vertices = 0;
        if(dfs_num[i][j] == UNVISITED) dfs(i,j);
        if(has_cycle()) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}