class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
    return a[1]<b[1];
   
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n= intervals.size();int count=0;
        sort(intervals.begin(),intervals.end(),comp);
        auto firststart= intervals[0][0];
        auto firstend= intervals[0][1];

        for( int i=1;i<intervals.size();i++){
            if(intervals[i][0]<firstend){count++;firstend=min(intervals[i][1],firstend);}
            else{firstend=intervals[i][1]; }

        }
        return count;
    }
};