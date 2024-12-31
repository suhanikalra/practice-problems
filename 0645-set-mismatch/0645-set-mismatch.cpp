class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int repeat=0,sum=0,n= nums.size();
        unordered_map<int,int>mp;
        for(auto k: nums){
            if(mp.find(k)== mp.end()){mp[k]++;sum+=k;}
            else repeat= k;
        }int p= n*(n+1)/2;
        return {repeat,p-sum};


    }
};