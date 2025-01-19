class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());vector<vector<int>>ans;
        int firststart=intervals[0][0];
        int firstend= intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            if(firstend>intervals[i][0]){
                firstend=min(intervals[i][1],firstend);
            }
            else{
                ans.push_back({firststart,firstend});
                firststart=intervals[i][0];
                firstend= intervals[i][1];

            }
            
        }
         
        ans.push_back({firststart,firstend});
        for(int i=0;i<ans.size();i++){cout<<ans[i][0]<<ans[i][1];}
            return intervals.size()- ans.size();
   
    }
};