class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count=0;int maxi=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='B')count++;
        }maxi= max(count,maxi);
        for(int i=k;i<blocks.size();i++){
            if(blocks[i-k]=='B')count--;
            if(blocks[i]=='B')count++;
            maxi= max(count,maxi);

        }
        return k-maxi;
        
    }
};