#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

typedef vector<int> vi;

class UnionFind {
    private:
        vi p, rank;

    public:
        UnionFind(int N) : p(N,0), rank(N,0) {
            for(int i = 0; i < N; ++i)
                p[i] = i;
        }

        int findSet(int i) {
            return p[i] == i ? i : ( p[i] = findSet(p[i]) );
        }

        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j) {
            if(!isSameSet(i, j)) {
                int x = findSet(i), y = findSet(j);
                if(rank[x] > rank[y])
                    p[y] = x;
                else {
                    p[x] = y;
                    if(rank[x] == rank[y])
                        rank[y]++;
                }
            }
        }
};

int main() {
    int TC;
    cin >> TC;
    while(TC--) {
        int nComputers;
        cin >> nComputers;
        UnionFind uf(nComputers);
        string line;
        int successful(0), unsuccessful(0);
        cin.ignore();
        char x;
        int y, z;
        while(getline(cin, line) && !line.empty()) {
            istringstream iss(line);
            iss >> x >> y >> z;
            if(x == 'c')
                uf.unionSet(y-1, z-1);
            else {
                if(uf.isSameSet(y-1, z-1))
                    ++successful;
                else
                    ++unsuccessful;
            }
        }
        cout << successful << "," << unsuccessful << endl;
        if(TC) cout << endl;
    }

    return 0;
}