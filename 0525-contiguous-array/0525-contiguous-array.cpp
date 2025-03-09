class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefix;
        
        int sum = 0;
        int maxi = 0;
        prefix[0] = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 0) ? -1 : 1;
            
            if(prefix.find(sum) != prefix.end()) {
                maxi = max(maxi, i - prefix[sum]);
            } else {
                prefix[sum] = i;
            }
        }
        
        return maxi;
    }
};