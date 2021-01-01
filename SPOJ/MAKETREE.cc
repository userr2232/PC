#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef set<int> si;
typedef vector<int> vi;

queue<int> q;
vi topo;
unordered_map<int, si> ancestors;
unordered_map<int, si> descendants;

void topological_sort() {
    auto u = q.front();
    topo.push_back(u);
    q.pop();
    if(!descendants.count(u)) return;
    for(auto v : descendants[u]) {
        ancestors[v].erase(u);
        if(!ancestors[v].size())
            q.push(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    for(int i = 1; i <= K; ++i) {
        int k;
        cin >> k;
        for(int j = 0; j < k; ++j) {
            int d;
            cin >> d;
            ancestors[d].insert(i);
            descendants[i].insert(d);
        }
    }

    for(int i = 1; i <= N; ++i)
        if(!ancestors.count(i))
            q.push(i);

    while(!q.empty())
        topological_sort();

    unordered_map<int,int> parent;
    parent[topo[0]] = 0;
    for(int i = 2; i <= N; ++i)
        parent[topo[i-1]] = topo[i-2];
    for(int i = 1; i <= N; ++i) 
        cout << parent[i] << endl;
}