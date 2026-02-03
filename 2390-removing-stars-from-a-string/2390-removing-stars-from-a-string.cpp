class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for( auto & k: s){
            if(k=='*')st.pop();
            else st.push(k);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;


    }
};