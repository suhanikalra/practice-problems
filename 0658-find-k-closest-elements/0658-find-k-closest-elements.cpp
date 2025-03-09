class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int end=0;
        priority_queue<pair<int,int>>pq;
    for(;end<arr.size();end++){
        pq.push({abs(x-arr[end]),arr[end]});
        if(pq.size()>k)pq.pop();


    }
   vector<int>ans;
       while(!pq.empty()){
        auto o= pq.top();
        pq.pop();
            ans.push_back(o.second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};