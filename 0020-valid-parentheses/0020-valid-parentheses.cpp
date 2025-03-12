class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto k: s) {
            if(k=='(' || k=='{' || k=='[') {
                st.push(k);
            } else if(k==')') {
                if(st.empty() || st.top()!='(') return false;
                st.pop();
            } else if(k=='}') {
                if(st.empty() || st.top()!='{') return false;
                st.pop();
            } else if(k==']') {
                if(st.empty() || st.top()!='[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};