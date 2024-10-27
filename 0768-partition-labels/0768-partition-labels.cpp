class Solution {
public:
    vector<int> partitionLabels(string s) {
        int i=0;
        vector<int> arr(26,0);
        for(auto c:s){
            arr[c-'a']=i++;

        }
        int start=0;
        int end=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
          end=max(end,arr[s[i]-'a']);
          if(i==end){
                ans.push_back(end - start + 1); start= end+1;}
    }
    return ans;
    }
};