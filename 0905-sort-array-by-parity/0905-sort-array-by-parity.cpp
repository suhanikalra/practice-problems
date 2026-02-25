class Solution {
public:
    static bool comp(int a, int b){
        auto x= a%2;
        auto y= b%2;
        return x<y;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort( nums.begin(),nums.end(),comp);
        return nums;

    }
};