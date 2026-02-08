class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind=0;

        for( int i=0;i<nums.size();i++){

            if( i>maxind)return false;
            auto jump= i+nums[i];
            maxind= max( maxind,jump);
        }
        return true;
    }
};