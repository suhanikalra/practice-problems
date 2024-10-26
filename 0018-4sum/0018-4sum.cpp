class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
if(nums.size()<4 )return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() ; i++) {
            if(i>0 && nums[i]==nums[i-1])continue;
            for (int j = i + 1; j < nums.size() ; j++) {
                if(j>i+1 && nums[j]==nums[j-1])continue;
             long long temp = target;
                int start = j + 1;
                auto end = nums.size() - 1;
                
                while (start < end) {
                  
                    if (nums[i] + nums[j] == temp-(nums[start] + nums[end] )) {
                        ans.push_back(
                            {nums[i], nums[j], nums[start], nums[end]});
                             while(start<end and nums[start]==nums[start+1]){
                        start++;}
                    while( start<end and nums[end]== nums[end-1]){end--;}
                        start++;
                        end--;
                        

                    } else {
                        if (nums[i] + nums[j]  >
                            temp- (nums[start] + nums[end]))
                            end--;
                        else
                            start++;
                    }

                     
                }
            }
        }
      

        return ans;
    }
};