class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(auto k: s){
            if(k>='a' and k<='z')
            st.push(k);

            if(k >= '0' && k <= '9' && !st.empty()) {
                st.pop();
            }}

            string m;
           if(!st.empty()){
           while(st.size()){
                m+=st.top();
                st.pop();
            }
           }
           reverse(m.begin(),m.end());
            return m;
        
    }
};