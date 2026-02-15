class Solution {
public:
int solveatmost(vector<int>& s, int k){
      unordered_map<int,int>mp;int count=0;
        int start=0,end=0;
        while(end<s.size()){
            mp[s[end]]++;
            while(mp.size()>k){
                mp[s[start]]--;
                if(mp[s[start]]==0)mp.erase(s[start]);
                start++;

            }
          
            count+=end-start+1;
            end++;
        }
        return count;
    

} 
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return solveatmost(nums,k)- solveatmost(nums,k-1);
    }
};