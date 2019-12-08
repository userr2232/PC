#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;

int main() {
    int m, n;
    while(cin >> m >> n) {
        vector<pair<ii,int> > matrix;
        for(int i = 0; i < m; ++i) {
            int cellsFilled;
            cin >> cellsFilled;
            if(!cellsFilled) {
                cin.ignore();
                string line;
                getline(cin, line);
                continue;
            }
            vector<int> columnsFilled;
            for(int k = 0; k < cellsFilled; ++k) {
                int x;
                cin >> x;
                columnsFilled.push_back(x-1); 
            }
            for(int k = 0; k < cellsFilled; ++k) {
                int value;
                cin >> value;
                matrix.push_back(make_pair(make_pair(i,columnsFilled[k]),value));
            }
        }
        for(int i = 0; i < matrix.size(); ++i) {
            swap(matrix[i].first.first,matrix[i].first.second);
        }
        sort(matrix.begin(), matrix.end());
        cout << n << " " << m << endl;
        int k = 0;
        for(int i = 0; i < n; ++i) {
            vector<ii> columnValue;
            while(matrix[k].first.first == i) {
                columnValue.push_back(make_pair(matrix[k].first.second+1,matrix[k].second));
                k++;
            }
            int tmp = columnValue.size();
            cout << tmp;
            for(int j = 0; j < tmp; ++j) {
                cout << " " << columnValue[j].first;
            }
            cout << endl;
            for(int j = 0; j < tmp; ++j) {
                cout << columnValue[j].second;
                if(j != tmp-1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}