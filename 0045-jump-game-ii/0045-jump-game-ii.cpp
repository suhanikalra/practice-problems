class Solution {
public:
    int jump(vector<int>& nums) {
        int steps=0; int maxreach=0;int end=0;
        
        for( int i=0;i<nums.size()-1;i++){
            if( i>maxreach)return -1;
            maxreach= max(maxreach,nums[i]+i);

            if( i==end){
                steps++;
                end= maxreach;
            }
        }
        return steps;
    }
};