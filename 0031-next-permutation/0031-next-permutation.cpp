class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation modifies nums in place
        next_permutation(nums.begin(), nums.end());
        return;
    }
};
