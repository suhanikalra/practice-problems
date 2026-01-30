class Solution {
public:
    int totalFruit(vector<int>& nums) {
      
    map<int,int>mp;int maxi=0;
    int start= 0;int end=0;
    while( end< nums.size()){
        mp[nums[end]]++;
        while( mp.size()>2){
            mp[nums[start]]--;
            if( mp[nums[start]]==0)mp.erase(nums[start]);
            start++;
        }
        maxi= max( maxi,end-start+1);end++;
        
    }
    return maxi;
}
    
};