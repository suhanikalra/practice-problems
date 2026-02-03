class Solution {
public:
    string removeDuplicates(string s) {
        string ans ="";stack<char>st;
        for( auto c:s){
            if( !st.empty() and st.top()==c){st.pop();ans.pop_back();}
            else{st.push(c);
            ans+=c;}
        }
        return ans;

    }
};