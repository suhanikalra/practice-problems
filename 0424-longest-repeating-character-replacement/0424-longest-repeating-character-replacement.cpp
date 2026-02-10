class Solution {
public:
    int characterReplacement(string s, int k) {
      unordered_map<char,int>freq;
      int start=0, end= 0,ans=0,max_freq=0;
      for(int end=0;end<s.size();end++){
        freq[s[end]]++;
        max_freq = max(max_freq, freq[s[end]]);
       while (end - start + 1 - max_freq > k){
          
        freq[s[start]]--;
        start++;
        }
         ans= max(ans,end-start+1); 
       

      } return ans; 
    }
};