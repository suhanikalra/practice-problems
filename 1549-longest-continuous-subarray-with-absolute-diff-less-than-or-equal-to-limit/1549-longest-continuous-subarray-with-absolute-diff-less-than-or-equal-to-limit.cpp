class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int start=0;int end=0;int count=0;
        multiset<int>ms;
        while(end<nums.size()){
            ms.insert(nums[end]);
            while (*ms.rbegin() - *ms.begin() > limit) {
                ms.erase(ms.find(nums[start])); 
                start++;
}
            count = max(count, end - start + 1);

            end++;
        }
        return count;
        
    }
};