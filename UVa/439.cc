#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <set>

using namespace std;

struct point {
    int x, y;
    point operator + (point other) {
        return {x + other.x, y + other.y};
    }
    bool operator == (point other) {
        return x == other.x && y == other.y;
    }
    bool operator < (point other) const {
        if(x < other.x) return true;
        else if(x > other.x) return false;
        else return y < other.y;
    }
};

vector<point> dirs;
set<point> visited;

bool out_of_bounds(point p) {
    auto [x, y] = p;
    if(x < 0 || x > 7 || y < 0 || y > 7) return true;
    return false;
}

int BFS(point p1, point p2) {
    queue<pair<point, int>> q;
    q.push({p1, 0});
    while(q.size()) {
        auto [p, step] = q.front();
        q.pop();
        visited.insert(p);
        if(p == p2) return step;
        for(auto dir : dirs) {
            auto p3 = p + dir;
            if(!out_of_bounds(p3) && !visited.count(p3))
                q.push({p3, step+1});
        }
    }
    return 0;
}

int main() {
    string a, b;
    for(int i = 1; i >= -1; i -= 2) {
        for(int j = 1; j >= -1; j -= 2) {
            dirs.push_back({2 * i, j});
            dirs.push_back({i, 2 * j});
        }
    }
    while(cin >> a >> b) {
        visited.clear();
        point p1{a[0]-'a',a[1]-'1'}, p2{b[0]-'a',b[1]-'1'};
        cout << "To get from " << a << " to " << b << " takes " << BFS(p1, p2) << " knight moves." << endl;
    }
}