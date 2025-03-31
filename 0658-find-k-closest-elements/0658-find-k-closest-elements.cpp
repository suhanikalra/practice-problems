class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>pq;  //maxheap is by default remember    
        for(auto ele: arr){pq.push({abs(ele-x),ele});
      if(pq.size()>k)pq.pop();}
      vector<int>ans;
      while(!pq.empty()){
        auto a= pq.top();
        ans.push_back(a.second);
        pq.pop();
      }
      sort(ans.begin(),ans.end());
      return ans;
    }
};