class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count = 0;
        // Find the minimum value in the array
        int minNum = *min_element(nums.begin(), nums.end());

        // Calculate the total moves required to equalize to the maximum value
        for (const auto& num : nums) {
            count += (num - minNum); // Count how many increments are needed
        }
        
        return count; // Return the total moves
    }
};
