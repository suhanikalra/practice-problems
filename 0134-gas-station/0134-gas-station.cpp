class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0;int a=0;
       int index=0;
        for( int i=0;i<gas.size();i++){
            a=a+(gas[i]-cost[i]);
             sum=sum+(gas[i]-cost[i]);
            if(a<0){
                index=i+1;a=0;
            }
            
        }
         if(  sum<0)return -1;
        return index;


    }
};