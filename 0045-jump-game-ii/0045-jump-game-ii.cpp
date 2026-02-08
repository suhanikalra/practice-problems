class Solution {
public:
    int jump(vector<int>& nums) {
          int maxind=0;int end=0;int jump=0;
        for( int i=0;i<nums.size()-1;i++){
         if( i>maxind)return -1;
            auto currjump= i+nums[i];
            maxind= max( maxind,currjump);
            if(end==i){
                end= maxind;jump++;
            }
        }
        return jump;
    }
};