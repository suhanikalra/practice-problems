class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int start=0,end=0;int ans=0;

        while(end<fruits.size()){
            mp[fruits[end]]++;
            while(mp.size()>2){
                mp[fruits[start]]--;
                if(mp[fruits[start]]==0)mp.erase(fruits[start]);
                start++;
                
            }
            ans=max(end-start+1,ans);end++;
        }
        return ans;
    }
};