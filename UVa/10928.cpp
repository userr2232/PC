#include<iostream>
#include<vector>
#include<utility>
#include<sstream>
#include<limits>
#include<algorithm>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    while(TC--) {
        string str;
        int P;
        cin >> P;
        cin.ignore();
        vector<int> nbrNumber(P,0);
        int minNum = numeric_limits<int>::max();
        for(int i = 0; i < P; ++i) {
            getline(cin, str);
            istringstream iss(str);
            int nbr;
            while(iss >> nbr) {
                ++nbrNumber[i];
            }
            if(minNum > nbrNumber[i]) {
                minNum = nbrNumber[i];
            }
        }
        vector<int> minNbrPlaces;
        for(int i = 0; i < nbrNumber.size(); ++i) {
            if(nbrNumber[i] == minNum) {
                minNbrPlaces.push_back(i+1);
            }
        }
        sort(minNbrPlaces.begin(),minNbrPlaces.end());
        for(int i = 0; i < minNbrPlaces.size(); ++i) {
            cout << (i == 0 ? "" : " ") << minNbrPlaces[i];
        }
        cout << endl;
        if(TC) {
            getline(cin,str);
        }
    }

    return 0;
}