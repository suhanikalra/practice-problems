class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int Odds = 0;

        for (int i = 0; i < arr.size(); i++) {
            
            if (arr[i] % 2 == 1) {
                Odds++;
            } else {
              Odds = 0;
            }

            if (Odds == 3) {
                return true;
            }
        }

        return false;
    }
};