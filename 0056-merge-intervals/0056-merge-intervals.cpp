class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort( intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int firststart= intervals[0][0];
        int firstend= intervals[0][1];
        for( int i=1;i<intervals.size();i++){
            if( firstend>=intervals[i][0] )firstend= max(intervals[i][1],firstend );
            else{ans.push_back({firststart,firstend});
                firststart= intervals[i][0];
                firstend= intervals[i][1];
            }
        }
        ans.push_back({firststart,firstend});
        return ans;

    }
};