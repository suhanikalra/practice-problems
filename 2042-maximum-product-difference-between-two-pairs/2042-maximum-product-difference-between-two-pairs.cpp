class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n= nums.size()-1;
        // return ( nums[n]*nums[n-1]-nums[0]*nums[1]);

     priority_queue<int> maxPq;
        priority_queue<int, vector<int>, greater<int>> minPq;
        
        for (auto num : nums) {
            maxPq.push(num);
            minPq.push(num);
        }
        
        int max1 = maxPq.top(); maxPq.pop();
        int max2 = maxPq.top();
        
        int min1 = minPq.top(); minPq.pop();
        int min2 = minPq.top();
        
        return max1 * max2 - min1 * min2;
    }
};