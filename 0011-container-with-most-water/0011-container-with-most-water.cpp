class Solution {
public:
    int maxArea(vector<int>& nums) {
        int start=0; int end= nums.size()-1;int maxi=0,area=0;

        while(start<=end){
            area=min(nums[start],nums[end])*(end-start);
            cout<<area;
            maxi=max(area,maxi);
            if(nums[start]<nums[end])start++;
            else end--;
        }
        return maxi;

    }
};