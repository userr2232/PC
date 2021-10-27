#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int,int,int> iii;

int main() {
    int n; cin >> n;
    priority_queue<iii> pq;
    for(int i = n; i >= 1; --i) {
        int id, m; cin >> id >> m;
        pq.emplace(m, i, id);
    }
    while(!pq.empty()) {
        int id, t, m;
        tie(m, t, id) = pq.top();
        pq.pop();
        cout << id << " " << m << endl;
    }
}