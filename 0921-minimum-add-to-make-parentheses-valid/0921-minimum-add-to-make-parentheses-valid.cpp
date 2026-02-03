class Solution {
public:
    int minAddToMakeValid(string s) {
         int i=0;int n=s.size(); 
        stack<int>st;
int count=0;
        for(auto &c: s){
            if( c=='(')st.push(i);
            
            else if( c==')' and !st.empty() )st.pop();
            else if( c==')' and st.empty() )count++;

            i++;
        }
        return st.size()+count;
       
        
    
    }
};