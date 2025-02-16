class Solution {
public:
    int maxDepth(string s) {
        int count=0;stack<char>st;int maxi=0;
        for(auto k: s){
            if(k=='('){ st.push('(');count++;}
            else if(k==')'){st.pop();maxi=max(count,maxi);count--; }
        }
        return maxi;
        
    }
};