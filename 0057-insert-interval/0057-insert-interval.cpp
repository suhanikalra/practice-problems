class Solution {
public:
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int firststart=intervals[0][0];
        int firstend= intervals[0][1];
        vector<vector<int>> ans;

        for(int i=0;i<intervals.size();i++){

        if(intervals[i][0]<=firstend){
            firstend= max(intervals[i][1],firstend);
        }
        if(intervals[i][0]>firstend){
            ans.push_back({firststart,firstend});
            firststart=intervals[i][0];
            firstend= intervals[i][1];
        }
        }
        ans.push_back({firststart,firstend});
        return ans;
        
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        for(auto k:intervals){
            ans.push_back(k);
        }
        ans.push_back(newInterval);
        return merge(ans);
    }
};