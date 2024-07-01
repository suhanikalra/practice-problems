class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // priority_queue<int> pq;
        // for(int num:nums)pq.push(num);
        // int ans= pq.top()-1;
        // pq.pop();
        // ans= ans* (pq.top()-1);
        // return ans;

        sort(nums.begin(),nums.end());
        return (nums[nums.size()-1]-1)*(nums[nums.size()-2]-1);
    }
};