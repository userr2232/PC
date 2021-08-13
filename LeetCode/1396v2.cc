class UndergroundSystem {
    unordered_map<int, pair<pair<int,string>,int>> checks;
    unordered_map<string,pair<double,int>> times;
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
        if(times.count(in_st + "#" + stationName)) {
            auto& [mean, num] = times[in_st+"#"+stationName];
            mean = (mean*num + out-in_t)/++num;
        }
        else times[in_st+"#"+stationName] = {out-in_t,1};
        checks.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return times[startStation+"#"+endStation].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */