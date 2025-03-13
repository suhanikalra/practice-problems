class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0,zero=0;
      
        for(int i=s.size()-1;i>=0;i--){
            char k=s[i];
            if(k=='0')zero++;
            if(k=='1')ans+=zero;
            cout<<zero<<" ";
        }
        return ans;
    }
};