class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        
        int firststart=intervals[0][0]; int firstend= intervals[0][1];
        vector<vector<int>>ans;

        for( int i=1;i<n;i++){
            if( intervals[i][0]<=firstend){
                firstend=max(intervals[i][1],firstend);
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