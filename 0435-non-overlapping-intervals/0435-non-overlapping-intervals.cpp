class Solution {
public:
static bool comp(vector<int>&a, vector<int>&b){
    return a[1]<b[1];
   
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int firststart=intervals[0][0];int firstend=intervals[0][1];
int count=0;
        for( int i=1;i<intervals.size();i++){
            if( intervals[i][0]<firstend){count++;firstend=min(intervals[i][1],firstend);}
            else {firstend=intervals[i][1];}
        }
        return count;


    }
};