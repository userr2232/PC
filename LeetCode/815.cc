class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map<int,vector<int>> m;
        const int n = routes.size();
        for(int i = 0; i < n; ++i) {
            const auto& route = routes[i];
            for(const auto& stop : route) 
                m[stop].emplace_back(i);
        }
        vector<bool> visited(n, false);
        int ans{0};
        queue<int> buses;
        for(auto&& bus : m[source]) buses.emplace(bus), visited[bus] = true;
        while(!buses.empty()) {
            ans++;
            int size = buses.size();
            for(int i = 0; i < size; ++i) {
                auto bus = buses.front();
                buses.pop();
                for(auto stop : routes[bus]) {
                    if(stop == target) return ans;
                    for(auto neighbor_bus : m[stop]) 
                        if(!visited[neighbor_bus]) 
                            buses.emplace(neighbor_bus), visited[neighbor_bus] = true;
                }
            }
        }
        return -1;
    }
};