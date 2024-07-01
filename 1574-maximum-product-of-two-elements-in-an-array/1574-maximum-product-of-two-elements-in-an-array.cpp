class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for(int num:nums)pq.push(num);
        int ans= pq.top()-1;
        pq.pop();
        ans= ans* (pq.top()-1);
        return ans;
    }
};