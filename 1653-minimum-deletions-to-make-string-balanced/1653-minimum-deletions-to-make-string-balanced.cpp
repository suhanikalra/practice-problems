class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;int count=0;
        for(auto c: s){
            if(!st.empty() and c=='a' and st.top()=='b'){
                count++;st.pop();
            }
           else  st.push(c);
        }
        return count;
    }
};