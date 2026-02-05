class Solution {
public: 
    int jump(vector<int>& nums) {
      
       
        int steps=0, max_reach=0,size=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if (i > max_reach)
                return -1;

              max_reach=max(max_reach,i+nums[i]);
             if(i==size)
             {
                 size=max_reach;
                 steps++;
             }
          
                
        }
        
        return steps;
    }
};