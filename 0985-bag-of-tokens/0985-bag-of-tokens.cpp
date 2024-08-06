class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int low=0,score= 0;
        int high = tokens.size()-1 ;

        while(low<=high){
            if(power>=tokens[low])
            {
                score+=1;
                power-=tokens[low++];
            } else if (low < high && score > 0) {
                score -= 1;
                power += tokens[high];
                high -= 1;
           
            } else {
                return score;
            }
        }
        return score;
    }
};