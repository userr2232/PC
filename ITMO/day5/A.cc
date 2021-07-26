#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> AdjList;
AdjList graph;
const int N = 1e3+10;
int n, x, dist[N];

void bfs(int u) {
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    while(!q.empty()) {
        int current = q.front(); q.pop();
        for(auto v : graph[current]) {
            if(dist[v] == -1) {
                dist[v] = dist[current]+1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> x;
    graph.resize(n+1);
    int tmp;
    FOR(i,1,n) FOR(j,1,n) {
        cin >> tmp;
        if(tmp) graph[i].push_back(j);
    }
    memset(dist,-1,sizeof dist);
    bfs(x);
    FOR(i,1,n) cout << dist[i] << " ";
}