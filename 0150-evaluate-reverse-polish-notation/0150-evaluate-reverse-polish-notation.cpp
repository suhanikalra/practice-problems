class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        
        for (auto &k : tokens) {
            if (k == "+" || k == "-" || k == "*" || k == "/") {
                auto first= st.top(); st.pop();
                auto sec= st.top(); st.pop();
                if(k=="+")st.push (first + sec);
                else if(k=="-")st.push(sec - first);
                else if(k=="*")st.push(sec * first);
                else if(k=="/")st.push(sec / first);        

        }
        else st.push(stoi(k));
        }
        return st.top();
    }
};