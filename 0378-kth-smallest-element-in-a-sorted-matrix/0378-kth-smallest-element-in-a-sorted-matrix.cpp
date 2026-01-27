class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>maxheap;
        for(auto row: matrix){
            for( auto ele: row){
                maxheap.push(ele);
                if(maxheap.size()>k)maxheap.pop();
            }
        }
        return maxheap.top();
    }
};