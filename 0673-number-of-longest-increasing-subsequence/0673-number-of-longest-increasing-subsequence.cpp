class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int ans=1;
        int n= nums.size();
        vector<int>dp(n,1);
        vector<int>count(n,1);
        
        for( int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if( nums[j]<nums[i]){
                    if( dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        count[i]=count[j];
                    }
                    else if( dp[j]+1==dp[i]){
                       count[i]= count[i]+count[j];}
                    
                    ans=max(ans,dp[i]);
                    
                }
            }
        }
        int gc=0;

        for( int i=0;i<nums.size();i++){
            if( dp[i]==ans)gc+=count[i];
        }
        return gc;
    }
};