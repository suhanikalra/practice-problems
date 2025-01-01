
class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        
        int prev_start = intervals[0][0];
        int prev_end = intervals[0][1];
        std::vector<std::vector<int>> ans; 

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > prev_end) { 
                ans.push_back({prev_start, prev_end});
                prev_start = intervals[i][0];
                prev_end = intervals[i][1];
            } else { 
                prev_end = std::max(prev_end, intervals[i][1]);
            }
        }

        ans.push_back({prev_start, prev_end});

        return ans;
    }
};
