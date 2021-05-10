#include <iostream>
#include <map>
#include <utility>
#include <set>

using namespace std;
typedef pair<int,int> ii;
typedef map<int, set<int>> graph;

int n, m, q;
set<int> colors;
map<ii, int> parent;

int rep(int a, int c) {
    auto p = parent[{a, c}];
    if(p == 0 || p == a) return p;
    return (parent[{a, c}] = rep(p, c));
}

void query() {
    int a, b;
    while(q--) {
        int ans{0};
        cin >> a >> b;
        for(int c : colors) {
            auto p = rep(a, c);
            if(p && p == rep(b, c))
                ++ans;
        }
        cout << ans << endl;
    }
}

void insert_to_dsu(int a, int b, int c) {
    int ra{rep(a, c)}, rb{rep(b, c)};
    if(ra && rb) parent[{rb, c}] = ra;
    else if(ra) parent[{b, c}] = ra;
    else if(rb) parent[{a, c}] = rb;
    else {
        parent[{a, c}] = a;
        parent[{b, c}] = a;
    }
}

void build_dsu() {
    int a, b, c;
    for(int i = 0 ; i < m; ++i) {
        cin >> a >> b >> c;
        colors.insert(c);
        insert_to_dsu(a, b, c);
    }
}

int main() {
    cin >> n >> m;
    build_dsu();
    cin >> q;
    query();
    return 0;
}