class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n= strs.size();
        string ans="";string first = strs[0];
        string last = strs[strs.size()-1];
        for (int i = 0; i < first.size() && i < last.size(); i++) {
            if(strs[0][i]==strs[n-1][i])ans=ans+strs[0][i];
            else break;

        }
        return ans;
    }
};