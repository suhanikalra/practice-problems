class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>,greater<int>>pq;long long cost=0;
        for(auto k: sticks){
            pq.push(k);
        }
       
        while(pq.size()>1){
           auto a=pq.top();pq.pop();auto b= pq.top();pq.pop();
           auto sum= a+b;
            cost+=sum;
            pq.push(sum);
        }
        return cost;

        
    }
};