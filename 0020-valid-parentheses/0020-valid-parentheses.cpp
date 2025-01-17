class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (c == '(' or c == '{' or c == '[')
                st.push(c);
            else if ((c == ')' and (st.empty() or st.top() != '(')))
                return false;
            else if ((c == '}' and (st.empty() or st.top() != '{')))
                return false;
            else if ((c == ']' and (st.empty() or st.top() != '[')))
                return false;
            else
                st.pop();
        }
        return st.empty();
    }
}; 