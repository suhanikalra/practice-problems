class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = 0, cnt1 = 0;
        int ele2 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            
            if (nums[i] == ele1)
                cnt1++;
            else if (nums[i] == ele2)
                cnt2++;
            
            else if (cnt1 == 0 ) {
                ele1 = nums[i];
                cnt1++;
            }
            else if (cnt2 == 0 ) {
                ele2 = nums[i];
                cnt2++;
            }
            else if (nums[i] != ele1 and nums[i] != ele2) {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == ele1)
                cnt1++;
            else if (num == ele2)
                cnt2++;
        }

        vector<int> ans;
        if (cnt1 > nums.size() / 3)
            ans.push_back(ele1);
        if (cnt2 > nums.size() / 3)
            ans.push_back(ele2);

        return ans;
    }
};