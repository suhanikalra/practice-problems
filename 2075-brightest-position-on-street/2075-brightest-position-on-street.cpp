class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        map<int, int> brightness;
        
        for (auto& k : lights) {
            int start = k[0] - k[1];  
            int end = k[0] + k[1];
            
            brightness[start]++;
            brightness[end + 1]--;
        }

        int curr = 0, maxi = 0, brightest_pos = 0;
        for (auto& [pos, change] : brightness) {
            curr += change;
            if (curr > maxi) {
                maxi = curr;
                brightest_pos = pos;
            }
        }
         
        return brightest_pos;
    }
};