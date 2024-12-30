class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
vector<vector<int>>result;
vector<int>ans;
int n= nums.size();
        for(int i=0;i<n;i++){
            int j= i+1;
            int k= nums.size()-1;
            while(j<k){
                if(nums[k]+nums[j]==-nums[i]){
                    ans.push_back({nums[i]});
                   ans.push_back({nums[j]});
                   ans.push_back({nums[k]});
                    result.push_back(ans);
                    ans.clear();
                    j++;
                    k--;}

                else if(nums[k]+nums[j]>-nums[i]){
                    k--;
                }
                else j++;
                }
            }
            set <vector<int>> s;
            for(auto k: result){
            s.insert(k);}
            result.clear();
            for(auto k: s){
                result.push_back(k);
            }
        return result;
        
    }
};