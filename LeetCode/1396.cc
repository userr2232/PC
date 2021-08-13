class UndergroundSystem {
    unordered_map<int, pair<pair<int,string>,int>> checks;
    map<pair<string,string>,vector<int>> times;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checks[id] = {{t, stationName},0};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& [in, out] = checks[id];
        auto& [in_t, in_st] = in;
        out = t;
        times[{in_st, stationName}].push_back(out-in_t);
        checks.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double ans{0};
        int i{0};
        for(auto t : times[{startStation, endStation}]) {
            i++;
            ans += t;
        }
        return ans/i;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */