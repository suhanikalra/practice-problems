class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        stack<char>st;
        for(auto k: s){
            if(k=='('){count++;st.push(k);}
            if(k==')'){if(!st.empty() and st.top()=='('){st.pop();count--;}else count++;}

        }
        return abs(count);
    }
};