class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int start=0,sum=0,maxi=INT_MIN,end=0;
        for(end;end<k;end++){
            sum+=nums[end];
        }
        maxi= sum;
        for(end;end<nums.size();end++){
            sum=sum+nums[end]-nums[start];
            start++;
            maxi= max(maxi,sum);
        }
       
        return maxi/(k*1.0)  ;  }
};