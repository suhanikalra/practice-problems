class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int  totalgas=0;  int totalcost=0;
        for(int i= 0;i<gas.size();i++){
             totalgas+= gas[i];
             totalcost+=cost[i];
        
        }
        if(totalgas<totalcost)return -1;
                int currentGas = 0, start = 0;

         for (int i = 0; i < gas.size(); i++) {
            currentGas += gas[i] - cost[i];
            
            if (currentGas < 0) {
                start = i + 1;
                currentGas = 0;
            }
        }

        return start;
       
        
    }
};