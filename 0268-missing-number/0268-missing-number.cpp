class Solution {
public:
    int missingNumber(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int start=0;
       int end= nums.size()-1;int mid;int ans=nums.size();
       while(start<=end){
        mid= (end-start)/2+start;
        if(nums[mid]-mid==0){start= mid+1;}
        else{ ans= mid; end= mid-1;}
       }
       return ans;
    }
};