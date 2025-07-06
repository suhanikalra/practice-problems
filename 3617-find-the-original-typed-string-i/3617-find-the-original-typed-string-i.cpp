class Solution {
public:
    int possibleStringCount(string word) {
        if (word.empty()) return 0;  
        auto prev=word[0];int ans=1;int count=1;
        for(int i=1;i<word.size();i++){
            if(word[i]==prev)count++;
            else{
                ans=ans+count-1;
                count=1;
            }
            prev=word[i];
        }
        ans=ans+count-1;
        
       return ans;

        

        
    }
};