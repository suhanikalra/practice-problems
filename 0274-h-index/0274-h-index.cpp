class Solution {
public:
    int hIndex(vector<int>& citations) {
        //can u explain me this ques
        sort(citations.begin(),citations.end(),greater<int>());
        int i;int ans=0;
        for(i=0;i<citations.size();i++){
            int index= i+1;
            if(citations[i]>=index )ans= index;
            else break;
        }
        
        return ans;
    }
};