class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int firststart= intervals[0][0];
        int firstend= intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=firstend){
                firstend= max(firstend,intervals[i][1]);
            }
            else{
                ans.push_back({firststart,firstend});
                firststart= intervals[i][0];
                firstend= intervals[i][1];
            }
        }
        ans.push_back({firststart,firstend});
        return ans;
        
    }
};