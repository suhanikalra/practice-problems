class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count = 0;
       
        int minNum = *min_element(nums.begin(), nums.end());

        
        for (const auto& num : nums) {
            count += (num - minNum); 
        }
        
        return count; 
    }
};
