class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       for(auto k: nums2){
        nums1.push_back(k);
        
       }
       int n=nums1.size();
       sort(nums1.begin(),nums1.end());
      if(nums1.size()%2==1) return nums1[nums1.size()/2];
    return (double)(nums1[n/2 - 1] + nums1[n/2]) / 2.0;
    }
};