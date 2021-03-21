#include <map>
#include <unordered_set>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    map<int, unordered_set<int>> adj;
    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    unordered_set<int> to_kick, remaining;
    for(int student = 1; student <= n; ++student) {
        remaining.insert(student);
    }
    int answer{0};
    while(true) {
        for(auto student : remaining) {
            if(adj[student].size() == 1)
                to_kick.insert(student);
        }
        if(!to_kick.empty()) {
            ++answer;
            for(auto student_to_kick : to_kick) {
                remaining.erase(student_to_kick);
                for(auto other_student : adj[student_to_kick])
                    adj[other_student].erase(student_to_kick);
            }
        }
        else{
            break;
        }
        to_kick = {};
    }
    cout << answer << endl;
}