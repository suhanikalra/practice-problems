class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //ngr 
        int n= temperatures.size();
        stack<int>st;vector<int>ans(n,0);
        for( int i=temperatures.size()-1;i>=0;i--){
            while(!st.empty() and  temperatures[i]>=temperatures[st.top()])st.pop();
            
            if(!st.empty())ans[i]=st.top()-i;
            
            st.push(i);
        }
        return ans;
    }
};

