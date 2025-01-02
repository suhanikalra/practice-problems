class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //solve kro abhi ka abhi
        int sum=0;int count=0;
        for(auto k: nums){sum+=k;}
        int mean= sum/nums.size();
        sort(nums.begin(),nums.end());
        int median= nums[nums.size()/2];
        if(median==mean){
            for(auto k: nums){
                count= count+ abs(k-mean);
            }
        }
        if(median>mean){
            for(auto k: nums){
                count= count+ abs(k-median);
            }


        }
        if(median<mean){
            for(auto k: nums){
                count= count+ abs(k-median);
            }
        }
        return count;
    }
};