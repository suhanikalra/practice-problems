class Solution {
public:
    void wiggleSort(vector<int>& nums) {
         std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
         priority_queue<int>maxHeap;
         for(auto k: nums){
            minHeap.push(k);
            maxHeap.push(k);
         }
int i=0;
         while(i<nums.size()){
            nums[i++]=minHeap.top();
            minHeap.pop();
            if(i<nums.size())nums[i++]=maxHeap.top();
            maxHeap.pop();

         }
         return ;
    }
};