#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <complex>
#include <cstring>
#define x real()
#define y imag()
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int N, x1_, y1_, x2_, y2_, dist[21][21];
vector<vii> p(21, vii(21,{-1,-1}));

vii neighbors(int x_, int y_) {
    vii ans;
    complex<double> current(x_,y_), dx(1,0), dy(0,1);
    FOR(i,-2,2) FOR(j,-2,2) if(abs(i) != abs(j) && i != 0 && j != 0) {
        auto neighbor = current + dx*(double)i + dy*(double)j;
        if(neighbor.x >= 1 && neighbor.x <= N && neighbor.y >= 1 && neighbor.y <= N)
            ans.push_back({neighbor.x, neighbor.y});
    }
    return ans;
}

void bfs() {
    queue<ii> q;
    q.push({x1_,y1_});
    dist[x1_][y1_] = 1;
    while(!q.empty()) {
        auto [x_, y_] = q.front(); q.pop();
        auto nbrs = neighbors(x_,y_);
        for(auto [xp, yp] : nbrs) {
            if(dist[xp][yp] == -1) {
                p[xp][yp] = {x_,y_};
                dist[xp][yp] = dist[x_][y_]+1;
                q.push({xp,yp});
                if(xp == x2_ && yp == y2_) return;
            }
        }
    }
}

void print(ii xy) {
    auto [x_, y_] = xy;
    if(p[x_][y_] == ii({-1,-1})) { cout << x_ << " " << y_ << endl; return; }
    print(p[x_][y_]);
    cout << x_ << " " << y_ << endl;
}

int main() {
    cin >> N >> x1_ >> y1_ >> x2_ >> y2_;
    memset(dist,-1,sizeof dist);
    bfs();
    cout << dist[x2_][y2_] << endl;
    print({x2_,y2_});
}