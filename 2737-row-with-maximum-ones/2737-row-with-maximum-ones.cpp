class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
       int count=0;int maxi= INT_MIN;int i=0;int index=0;
        for(auto row:mat){
            for (auto k: row){
            if(k==1){count++;}}
        
        if(maxi<count){
            maxi= count;
            index=i;
           } i++;
            count=0;
        } 

        return {index,maxi};

    }

};