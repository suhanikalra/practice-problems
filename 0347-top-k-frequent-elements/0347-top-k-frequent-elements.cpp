class Solution { //bad approach use minheap
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map <int,int>freq;
        for(auto num: nums){
            freq[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
       
            
       for (const auto& entry : freq) {
            minHeap.push({entry.second, entry.first}); 
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

    
        for (int i = 0; i < k && !minHeap.empty(); ++i) {
            ans.push_back(minHeap.top().second); 
            minHeap.pop();
        }

        return ans; 
    }
};