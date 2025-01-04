class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int firststart= intervals[0][0];
        int firstend= intervals[0][1],count=0;

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<firstend){count++;firstend=min(firstend,intervals[i][1]);}
            else{
                firststart= intervals[i][0];
         firstend= intervals[i][1];
            }
        
        }
        return count;
    }
};