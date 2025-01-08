class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st; 
        
        for (auto k : s) {
            if (!st.empty() && st.top() == k) {
                st.pop();
            } else {
                st.push(k);
            }
        }

        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
