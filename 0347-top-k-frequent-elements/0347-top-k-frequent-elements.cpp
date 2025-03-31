class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto num: nums){
            mp[num]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//minheap
        for(auto &[x,y]: mp){
            pq.push({y,x});
            if(pq.size()>k)pq.pop();

        }
        vector<int>ans;
        while(!pq.empty()){
            auto a= pq.top();pq.pop();
            ans.push_back(a.second);
        }
        return ans;

        
    }
};