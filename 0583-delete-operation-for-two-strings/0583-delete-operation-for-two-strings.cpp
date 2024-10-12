class Solution {
public:
int solve(string &text1, string &text2,vector<vector<int>> &dp,int i,int j){
        if(i==text1.size()|| j== text2.size()){
            return 0;
        }
        if(dp[i][j] != -1 ) return dp[i][j];

        if(text1[i]==text2[j]){
          return dp[i][j]= solve(text1,text2,dp,i+1,j+1)+1;
            
        }
        else{
           return dp[i][j]= max(solve(text1,text2,dp,i+1,j),solve(text1,text2,dp,i,j+1));
        }
    }

    int minDistance(string word1, string word2) {
         int m= word1.size();
        int n= word2.size();
        vector<vector<int>> dp(m,vector<int>(n, -1));
        return m+n-2*solve(word1,word2,dp,0,0);
    }
};