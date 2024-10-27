class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map <int,int>freq;
        for(auto num: nums){
            freq[num]++;
        }
 priority_queue<pair<int, int>> maxHeap;
       
            
       for (const auto& entry : freq) {
            maxHeap.push({entry.second, entry.first}); 
        }

    
        for (int i = 0; i < k && !maxHeap.empty(); ++i) {
            ans.push_back(maxHeap.top().second); 
            maxHeap.pop();
        }

        return ans; 
    }
};