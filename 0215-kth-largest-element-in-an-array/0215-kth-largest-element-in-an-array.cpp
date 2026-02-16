class Solution {
public:
priority_queue<int,vector<int>,greater<int>>pq;
    int findKthLargest(vector<int>& nums, int k) {
        for( auto num: nums){
            pq.push( num);
            if( num.size()>k)pq.pop();
        }
        return pq.top();
    }
};