class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(auto i: nums){
            pq.push(i);
        }
        int count=0;
        while(pq.size()>=2){
        
           auto a= pq.top();
           if(pq.top()>=k)break;
           pq.pop();
           auto b= pq.top();
           pq.pop();

           long long c= min(a,b)*2+ max(a,b);
           pq.push(c);
           count++;

        
        }
        return count;
    }
};