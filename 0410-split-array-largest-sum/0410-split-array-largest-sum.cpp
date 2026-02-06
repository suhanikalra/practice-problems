class Solution {
public:
int solve( int mid,vector<int>& nums, int k ){
    int count=1;int sum=0;
    for( int i=0;i<nums.size();i++){
        if(nums[i]>mid)return false;
        sum+=nums[i];
        if( sum>mid){sum=nums[i];count++;
        }

        
    }
    return count<=k;
}
    int splitArray(vector<int>& nums, int k) {
     int low=0; int high = accumulate(nums.begin(), nums.end(), 0);int ans=-1;
        int mid= ( high-low)/2+low;
        while( low<=high){
            mid= ( high-low)/2+low;
            if (solve(mid, nums, k)){ans=mid;high= mid-1;}
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};