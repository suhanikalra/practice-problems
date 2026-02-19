class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
         unordered_map<int,int> mp;bool found=false;
        mp[0] = 1; int sum=0;int ans=0;
        for( auto num: nums){
            if( num>k){
                sum+=1;
            }
            else if( num<k){sum-=1;}
            else if(num==k)found=true;
            if( found){
                ans=ans+ mp[sum]+mp[sum-1];
            }
            else {
                mp[sum]++;
            }

        }
        return ans;
    }
};