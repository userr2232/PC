#include<iostream>
#include<vector>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    while(TC--) {
        int n, m;
        cin >> n >> m;
        vector<vector<bool> > matrix(n,vector<bool>(m,false));
        bool M;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> M;
                matrix[i][j] = M;
            }
        }
        bool ok = true;
        for(int i = 0; i < m; ++i) {
            int sum(0);
            for(int j = 0; j < n; ++j)
                if(matrix[j][i])
                    sum++;
            if(sum != 2) {
                ok = false;
                break;
            }
        }
        if(ok){
            vector<vector<bool> > existsEdge(n,vector<bool>(n,false));
            for(int i = 0; i < m; ++i) {
                int start(0), end(0), k(0);
                while(!matrix[k++][i]);
                start = k - 1;
                while(!matrix[k++][i]);
                end = k - 1;
                if(!existsEdge[start][end])
                    existsEdge[start][end] = existsEdge[end][start] = true;
                else {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}