class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort( intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int firststart=intervals[0][0];int firstend=intervals[0][1];

        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]<=firstend){
                firstend=max(firstend,intervals[i][1]);
            }
            else{
                ans.push_back({firststart,firstend});
                firstend=intervals[i][1];
                firststart=intervals[i][0];

            }
        }
        ans.push_back({firststart,firstend});
        return ans;

    }
};