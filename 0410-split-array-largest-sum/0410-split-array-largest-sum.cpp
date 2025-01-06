class Solution {
public:
bool solve(int mid,vector<int>& nums, int k){
     int sum = 0;
        int count = 1; 
        for (auto num : nums) {
            if (num > mid) return false; 
            if (sum + num > mid) {
                
                count++;
                sum = num;
                if (count > k) return false;
            } else {
                sum += num;
            }
        }
        return count <= k; 
    }
    int splitArray(vector<int>& nums, int k) {
        int ans=0;
        int start=0;int end=accumulate(nums.begin(), nums.end(), 0);
       
        while(start<=end){
            int mid= (end-start)/2+start;
            if(solve(mid,nums,k)==true){ans=mid;end=mid-1;}
            else if(solve(mid,nums,k)!=true)start=mid+1;

        }
        return ans;
    }
};