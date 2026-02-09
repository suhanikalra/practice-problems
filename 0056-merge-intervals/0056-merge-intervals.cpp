class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int firstStart= intervals[0][0];
        int firstEnd= intervals[0][1];
        vector<vector<int>>ans;

        for( int i=1;i<intervals.size();i++){
            if( intervals[i][0]<=firstEnd){
                firstEnd= max(firstEnd,intervals[i][1] );
            }
            else{
                ans.push_back({firstStart,firstEnd});
                firstStart= intervals[i][0];
                firstEnd= intervals[i][1];
            }
        }
        ans.push_back({firstStart,firstEnd});
        return ans;
    }
};