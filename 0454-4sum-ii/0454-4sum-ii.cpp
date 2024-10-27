class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n= nums1.size();
        int sum=-6;
        int count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++ ){
            for(auto nums: nums2){
                sum= nums+ nums1[i];
                mp[sum]++;

            }
        }

        for(int i=0;i<n;i++ ){
            for(auto nums: nums4){
                sum= nums+ nums3[i];
               if( mp.contains(-sum)){count+=mp[-sum];
              

            }
        }
        }

      return count;




    }
};