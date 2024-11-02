class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> arr(26,0);
       auto i=0;
        for( char c: s){
            arr[c-'a']=i++;
        }
 int start = 0, end = 0;
        
        for (int i = 0; i < s.size(); i++) {
            end = max(end, arr[s[i] - 'a']);
            
            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};