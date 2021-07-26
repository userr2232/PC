#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;
string s;
bool taken[60];
vector<int> v;
priority_queue<int> pq;

bool search(int id = 0) {
    if(id == s.size()) {
        pq = priority_queue<int>();
        for(auto e : v) pq.push(e);
        if(pq.size() != pq.top()) return false;
        for(auto e : v) cout << e << " "; v.clear(); return true; 
    }
    if(s[id]=='0') return false;
    else if(!taken[s[id]-'0']) {
        taken[s[id]-'0'] = true;
        v.push_back(s[id]-'0');
        auto x = search(id+1);
        if(x) return x;
        taken[s[id]-'0'] = false;
        v.pop_back();
        if(id < s.size()-1 && s[id]-'0'!= 0 && (s[id]-'0' < 5 || (s[id]-'0' == 5 && s[id+1]-'0' == 0))) {
            if(!taken[(s[id]-'0')*10 + s[id+1]-'0']) {
                taken[(s[id]-'0')*10 + s[id+1]-'0'] = true;
                v.push_back((s[id]-'0')*10 + s[id+1]-'0');
                auto y = search(id+2);
                if(y) return y;
                taken[(s[id]-'0')*10 + s[id+1]-'0'] = false;
                v.pop_back();
                return false;
            }
            return false;
        }
        return false;
    }
    else if(id == s.size()-1) {
        return false;
    }
    else  if(taken[(s[id]-'0')*10 + s[id+1]-'0']) { return false; }
    else if(s[id]-'0' < 5 || (s[id]-'0' == 5 && s[id+1]-'0' == 0)) {
        taken[(s[id]-'0')*10 + s[id+1]-'0'] = true;
        v.push_back((s[id]-'0')*10 + s[id+1]-'0');
        auto y = search(id+2);
        if(y) return y;
        taken[(s[id]-'0')*10 + s[id+1]-'0'] = false;
        v.pop_back();
        return false;
    }
    return false;
}

int main() {
    cin >> s;
    search();
}