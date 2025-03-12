class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg=0,pos=0;
        for(auto k: nums){
            if(k<0)neg++;
            if(k>0)pos++;
        }
        return max(pos,neg);
        
    }
};