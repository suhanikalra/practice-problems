class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> buildings;
        int maxSoFar = 0;
        for (int i=heights.size()-1;i>-1;i--)
        {
            if (heights[i] > maxSoFar)
            {
                buildings.push_back(i);
                maxSoFar = heights[i];
            }
        }
        
        reverse(buildings.begin(), buildings.end());

        return buildings; 
    }
};