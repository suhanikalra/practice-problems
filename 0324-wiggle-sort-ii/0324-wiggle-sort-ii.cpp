class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>k=nums;
        sort(k.begin(),k.end(),greater<int>());int j=0;
        int m=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(i%2==1)nums[i]=k[j++];
            

        } 
        for(int i=0;i<nums.size();i++){
            if(i%2==0)nums[i]=k[j++];
            

        } 

            
         
        
    }
};