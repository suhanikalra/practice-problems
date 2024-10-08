class Solution {
public:

    int solve(string &word1, string &word2, vector<vector<int>>&dp,int i,int j){
        // if(i==word1.size() and j==word2.size()){
        //     return 0;
        // }
        if (i == word1.size()) return word2.size() - j;  // If word1 is exhausted, insert remaining characters of word2
        if (j == word2.size()) return word1.size() - i;

        
  if (dp[i][j] != -1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j]=solve(word1,word2,dp,i+1,j+1);

        int ans= min(solve(word1,word2,dp,i+1,j+1)+1,solve(word1,word2,dp,i+1,j)+1);
        return dp[i][j]= min(ans,solve(word1,word2,dp,i,j+1)+1);
        
        
    }



    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
       return solve( word1, word2,dp,0,0);
        
    }
};