class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int start=0, i=0; double sum=0,maxi=0;
        for( i= 0;i<k;i++){
            sum+=nums[i];

        }
        maxi= max(maxi,sum);
        for( i;i<nums.size();i++){
            sum=sum+ nums[i]-nums[start];start++;
            maxi= max(maxi,sum);
        }
        return maxi/(k*1.0); 

        
    }
};