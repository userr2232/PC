#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<char,pair<int,pair<int,bool>>> m {
        {'S',{0,{0,false}}},
        {'H',{1,{0,false}}},
        {'D',{2,{0,false}}},
        {'C',{3,{0,false}}}
    };
    char tmp[3]; int points[] = {0,0};
    int pos;
    vector<bool> J = {false,false,false,false};
    vector<bool> A(J), K(J), Q(J);

void clear(){
    A.clear(); K.clear(); Q.clear(); J.clear();
    A = {false,false,false,false};
    K = Q = J = A;
    m = {
        {'S',{0,{0,false}}},
        {'H',{1,{0,false}}},
        {'D',{2,{0,false}}},
        {'C',{3,{0,false}}}
    };
    points[0] = points[1] = 0;
}


int main(){
    int count = 0;
    while(scanf("%s", tmp) == 1 && ++count){
        char suit = tmp[1];
        char rank = tmp[0];
        m[suit].second.first++;
        pos = m[suit].first;
        switch(rank){
            case 'A':
                points[0] += 4;
                A[pos] = true;
                m[suit].second.second = true;
                break;
            case 'K':
                points[0] += 3;
                K[pos] = true;
                break;
            case 'Q':
                points[0] += 2;
                Q[pos] = true;
                break;
            case 'J':
                points[0]++;
                J[pos] = true;
                break;
            default:
                break;
        }
        if(count == 13){
            count = 0;
            vector<int> nums;
            char maxSuit = 'S';
            int maxNum = m[maxSuit].second.first;
            for(map<char,pair<int,pair<int,bool>>>::iterator it=m.begin(); it!=m.end(); ++it){
                int e = it->second.first, num = it->second.second.first;
                if(it->second.first < m[maxSuit].first && it->second.second.first == maxNum)
                    maxSuit = it->first;
                else if(it->second.second.first > maxNum)
                    maxSuit = it->first, maxNum = it->second.second.first;
                nums.push_back(num);
                bool& stopped = it->second.second.second;
                if(K[e] && num < 2)
                    points[0]--;
                else if(K[e] && num >= 2)
                    stopped = true;
                if(Q[e] && num < 3)
                    points[0]--;
                else if(Q[e] && num >= 3)
                    stopped = true;
                if(J[e] && num < 4)
                    points[0]--;
                if(num == 2)
                    points[1]++;
                else if(num == 1)
                    points[1] += 2;
                else if(num == 0)
                    points[1] += 2;
            }
            if((points[0] >= 16) && m['S'].second.second && m['H'].second.second && m['D'].second.second && m['C'].second.second){
                printf("BID NO-TRUMP\n");
            }
            else if(points[0] + points[1] >= 14){
                printf("BID %c\n", maxSuit);
            }
            else{
                printf("PASS\n");
            }
            clear();
        }
    }

    return 0;
}
