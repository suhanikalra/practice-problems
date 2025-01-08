class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        priority_queue<double>maxheap;int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        maxheap.push(sum);
        for(int i=k;i<nums.size();i++){
            sum=sum-nums[i-k]+nums[i];
            maxheap.push(sum);
        }
        return maxheap.top()/k;
        
        
    }
};