#include <vector>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;

class UnionFind {
private: vi p, rank;
public:
    UnionFind(int n) {
        p.assign(n, 0);
        rank.assign(n, 0);
        FOR(i,0,n-1) p[i] = i;
    }
    int findSet(int i) {
        return p[i] == i ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        int x{findSet(i)}, y{findSet(j)};
        if(rank[x] > rank[y]) p[y] = x;
        else {
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
};