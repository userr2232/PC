#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
    int TC;
    cin >> TC;
    cin.ignore();
    string line;
    while(TC--) {
        int nEdgesOfVertex['Z' - 'A' + 1] = {}; int edges(0), vertex(0), acorns(0);
        while(getline(cin,line), line[0] != '*') {
            nEdgesOfVertex[line[1] - 'A']++;
            nEdgesOfVertex[line[3] - 'A']++;
            edges++;
        }
        getline(cin, line);
        for(int i = 0; i < line.size(); i+=2) {
            if(!nEdgesOfVertex[line[i] - 'A']) {
                acorns++;
            }
            vertex++;
        }
        cout << "There are " << vertex - edges - acorns << " tree(s) and " << acorns << " acorn(s)." << endl;
    }
}