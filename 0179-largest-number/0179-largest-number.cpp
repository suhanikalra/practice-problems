class Solution {
public:

    string largestNumber(vector<int>& nums) {
        auto comp= [](int &a,int &b){
            auto p= to_string(a);
            auto q= to_string(b);
            return p+q>q+p;
        };
        sort(nums.begin(),nums.end(),comp);
        if(nums[0]==0)return "0";
        string ans="";
        for(auto k:nums){
            ans=ans+to_string(k);
        }
        return ans;

    }
};