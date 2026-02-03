class Solution {
public:
const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n= arr.size();
        vector<int>nsl(n,-1);
        vector<int>nsr(n,n);
        stack<int>leftst;
        stack<int>rightst;

        for(int i=0;i<n;i++){
            while(!leftst.empty() and arr[leftst.top()]>=arr[i])leftst.pop();
            
           if(!leftst.empty()) nsl[i]=leftst.top();
           leftst.push( i);
            
        }

        for( int i=n-1;i>=0;i--){
            while(!rightst.empty() and arr[rightst.top()]>arr[i])rightst.pop();
            if(!rightst.empty()) nsr[i]=rightst.top();
           rightst.push( i);

        }
        long long ans=0;
       for (int i = 0; i < n; i++) {
            long long left = i - nsl[i];
            long long right = nsr[i] - i;
            ans = (ans + arr[i] * left % MOD * right % MOD) % MOD;
        }

        return ans;

    }
};