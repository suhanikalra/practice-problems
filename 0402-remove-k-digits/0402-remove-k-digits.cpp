class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() <= k) return "0";

        stack<char> st;

      
        for (auto i : num) {
            while (!st.empty() && st.top() > i && k > 0) {
                st.pop();
                k--;
            }
            st.push(i);
        }

        
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

     
        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }
        result.erase(0, i);

      
        return result.empty() ? "0" : result;
    }
};
