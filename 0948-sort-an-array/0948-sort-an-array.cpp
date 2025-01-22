class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue <int, vector<int>, greater<int> > q;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        int i=0;
        while(q.size() != 0){
            int temp = q.top();
            nums[i] = temp;
            i++;
            q.pop();
        }
        return nums;
    }
};