class Solution {
public:
    int minAddToMakeValid(string s) {
// )))((()))
        stack<char> st;

        for (auto c : s) {
            
            if (c == '(')
                st.push(c);
            if (c == ')')
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else st.push(c);
        }
        return st.size();
    }
};