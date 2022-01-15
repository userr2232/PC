class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int max_height_to_right{0};
        vector<int> buildings;
        for(int i = heights.size()-1; i >= 0; --i)
            if(heights[i] > max_height_to_right)
                buildings.emplace_back(i), max_height_to_right = heights[i];
        reverse(buildings.begin(), buildings.end());
        return buildings;
    }
};