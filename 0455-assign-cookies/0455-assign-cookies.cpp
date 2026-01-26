class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        int count=0;
        sort( s.begin(),s.end());

        int i=g.size()-1; int j=s.size()-1;
        while( i>=0 and j>=0){
            
             if( g[i]<=s[j]){count++;j--;i--;}
             else i--;
        }
        return count;
    }
};