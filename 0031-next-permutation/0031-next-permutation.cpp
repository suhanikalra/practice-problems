class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size()-1;int to_swap=-1;
        for( int i=n;i>=1;i--){
            if( nums[i]>nums[i-1]){to_swap= i-1;break;}
        }
        if( to_swap==-1){
            reverse( nums.begin(),nums.end());return;
        }
        for( int i=n;i>=1;i--){
            if( nums[i]>nums[to_swap]){
                swap( nums[i],nums[to_swap]);break;
            }
        }
        reverse(nums.begin()+to_swap+1,nums.end() );
        
    }
};