class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m= g.size();
        int n= s.size();
        int content=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l=0,r=0;
       while (l < m && r < n) {
        if(g[l]<=s[r]){
            content++;
            r++;
            l++;
        }
        else r++;


    }
    return content;
    }
};
