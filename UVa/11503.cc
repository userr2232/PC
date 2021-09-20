#include <iostream>
#include <vector>
#include <unordered_map>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

class UnionFind{
private:
vi p, rank, size;
public:
    UnionFind(int n) {
        p.resize(n);
        rank.assign(n,0);
        size.assign(n,1);
        FOR(i,0,n-1) p[i] = i;
    }

    int findSet(int i) {
        return p[i] == i ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    int unionSet(int i, int j) {
        int x{findSet(i)}, y{findSet(j)};
        if(x == y) return size[x];
        if(rank[x] > rank[y]) {
            p[y] = x;
            size[x] += size[y];
            return size[x];
        }
        else {
            p[x] = y;
            size[y] += size[x];
            if(rank[x] == rank[y]) rank[y]++;
            return size[y];
        }
    }
};

int main() {
    int TC; cin >> TC;
    while(TC--) {
        int personCounter;
        unordered_map<string, int> name_id;
        int E; cin >> E;
        vector<ii> edges;
        while(E--) {
            string name1, name2; cin >> name1 >> name2;
            vector<string> names = {name1, name2};
            for(auto name: names) {
                auto [it, inserted] = name_id.emplace(name, 0);
                if(inserted) it->second = personCounter++;
            }
            edges.emplace_back(name_id[name1], name_id[name2]);
        }
        UnionFind uf(personCounter);
        for(auto [u, v] : edges) cout << uf.unionSet(u, v) << endl;
    }
    return 0;
}