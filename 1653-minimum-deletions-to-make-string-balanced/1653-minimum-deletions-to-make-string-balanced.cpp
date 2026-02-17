class Solution {
public:
    int minimumDeletions(string s) {
         stack<char>st;int count=0;
         for( auto c: s){
          
            if( !st.empty() and st.top()=='b' and c=='a' ){st.pop();count++;}
            else st.push(c);
         }
         return count;
    }
};