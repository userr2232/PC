#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <set>

using namespace std;

typedef vector<int> vi;

class UnionFind {

    private:
    vi p, rank;
    int size;

    public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i = 0; i < N; ++i) {
            p[i] = i;
        }
        size = N;
    }

    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if(!isSameSet(i, j)) {
            int x = findSet(i);
            int y = findSet(j);
            if(rank[x] > rank[y]) {
                p[y] = x;
            }
            else {
                p[x] = y;
                if(rank[x] == rank[y])
                    rank[y]++;
            }
            size--;
        }
    }

    int getSize() {
        return size;
    }
};

int main() {
    int TC;
    cin >> TC;
    while(TC--) {
        int P, T, p, t;
        cin >> P >> T;
        string line;
        getline(cin, line);
        map<int, set<int>> obs;
        while(getline(cin, line), !line.empty()) {
            istringstream iss(line);
            iss >> p >> t;
            obs[p-1].insert(t-1);
        }
        UnionFind opinions = UnionFind(P);
        for(int i = 0; i < P-1; ++i) {
            for(int j = i + 1; j < P; ++j) {
                if(obs.count(i) && obs.count(j)) {
                    if(obs[i] == obs[j])
                        opinions.unionSet(i, j);
                }
                else if(obs.count(i) == obs.count(j)) {
                    opinions.unionSet(i, j);
                }
            }
        }
        cout << opinions.getSize() << endl;
        if(TC)
            cout << endl;
    }
    return 0;
}