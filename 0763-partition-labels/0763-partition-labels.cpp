class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;int end=0;int partition=0;
        int start = 0;vector<int>ans;

        for( int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }

         for( int i=0;i<s.size();i++){
            
            end= max( mp[s[i]],end);
            if( end==i){

                partition++;
                ans.push_back( end-start+1);
                start=i+1;
                end=i+1;
            }
         }
         return ans;
        
    }
};