class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int black=0;int end=0;int maxi=0;
       for(;end<k;end++){
        if(blocks[end]=='B')black++;
       }
       maxi=max(black,maxi);
       for(;end<blocks.size();end++){
        if(blocks[end]=='B')black++;
        if(blocks[end-k]=='B')black--;
        maxi=max(black,maxi);

       }
       return k-maxi;
  
    }
};