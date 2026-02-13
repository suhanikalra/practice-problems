class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index=0;int sum=0;int currsum=0;
        for( int i=0;i<gas.size();i++){
             sum= sum+gas[i]-cost[i];
             currsum= currsum+gas[i]-cost[i];
            if( currsum<0){index=i+1;currsum= 0;}
        }
        if( sum<0)return -1;
        return index;

    }
};