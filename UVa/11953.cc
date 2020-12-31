#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

class UnionFind {
private:
    vi p, rank;
public:
    int N;
    vb isBoatPart;
    vb isAlive;
    UnionFind(int N): N{N} {
        rank.assign(N*N, 0);
        p.assign(N*N, 0);
        isBoatPart.assign(N*N, false);
        isAlive.assign(N*N, false);
        for(int i = 0; i < N*N; ++i)
            p[i] = i;
    }

    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i , int j) {
        return findSet(i) == findSet(j);
    }

    bool unionSet(int i, int j) {
        int x{findSet(i)}, y{findSet(j)};
        if(rank[x] > rank[y]) {
            p[y] = x;
            if(!isAlive[x] && isAlive[y]) {
                return isAlive[x] = true;
            }
        }
        else {
            p[x] = y;
            if(rank[x] == rank[y])
                rank[y]++;
            if(!isAlive[x] && isAlive[y]) {
                return true;
            }
            else if(isAlive[x] && !isAlive[y]) {
                isAlive[y] = true;
            }
        }
        return false;
    }
};

bool addPart(UnionFind& u, int i, int j, char t) {
    int id = u.N * i + j;
    u.isBoatPart[id] = true;
    if(t == 'x')
        u.isAlive[id] = true;
    if(i > 0) {
        int top_id = u.N * (i - 1) + j;
        int top_root_id = u.findSet(top_id);
        if(u.isBoatPart[top_root_id]) {
            return u.unionSet(top_root_id, id);
        }
    }
    if(j > 0) {
        int left_id = u.N * i + j - 1;
        int left_root_id = u.findSet(left_id);
        if(u.isBoatPart[left_root_id]) {
            return u.unionSet(left_root_id, id);
        }
    }
    return u.isAlive[id];
}

int main() {
    int TC;
    cin >> TC;
    for(int c = 1; c <= TC; c++) {
        int N;
        cin >> N;
        char cur;
        UnionFind u(N);
        int count{0};
        string str;
        for(int i = 0; i < N; ++i) {
            cin >> str;
            istringstream iss(str);
            for(int j = 0 ; j < N; ++j) {
                iss >> cur;
                if(cur != '.')
                    if (addPart(u, i, j, cur))
                        count++;
            }
        }
        cout << "Case " << c << ": " << count << endl;
    }
}