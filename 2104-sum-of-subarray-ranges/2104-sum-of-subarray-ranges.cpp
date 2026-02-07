class Solution {
public:

    long long subArrayRanges(vector<int>& nums) {
        int n= nums.size();
       vector<int>nsl(n,-1);
        vector<int>nsr(n,n);
        vector<int>ngr(n);vector<int>ngl(n);

        stack<int>leftst,st;
        stack<int>rightst;

        for(int i=0;i<n;i++){
            while(!leftst.empty() and nums[leftst.top()]>=nums[i])leftst.pop();
            
           if(!leftst.empty()) nsl[i]=leftst.top();
           leftst.push( i);
            
        }

        for( int i=n-1;i>=0;i--){
            while(!rightst.empty() and nums[rightst.top()]>nums[i])rightst.pop();
            if(!rightst.empty()) nsr[i]=rightst.top();
           rightst.push( i);

        }
        // NGL (max)
        while(!st.empty()) st.pop();
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            ngl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // NGR (max)
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            ngr[i] = st.empty() ? n : st.top();
            st.push(i);
        }

       long long minsum = 0, maxsum = 0;

        for(int i = 0; i < n; i++) {
            long long leftMin = i - nsl[i];
            long long rightMin = nsr[i] - i;
            minsum += nums[i] * leftMin * rightMin;

            long long leftMax = i - ngl[i];
            long long rightMax = ngr[i] - i;
            maxsum += nums[i] * leftMax * rightMax;
        }

        return maxsum - minsum;


    }
};