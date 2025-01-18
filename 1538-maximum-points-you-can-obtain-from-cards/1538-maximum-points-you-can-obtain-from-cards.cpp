class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int start = 0, end = 0, mini = INT_MAX, sum = 0;

        if (k > cardPoints.size()) return -1;
        for (end = 0; end < cardPoints.size() - k; end++) {
            sum += cardPoints[end];
        }
        mini = min(sum, mini);

       
        for (; end < cardPoints.size(); end++) {
            sum = sum - cardPoints[start] + cardPoints[end];
            start++;
            mini = min(sum, mini);
        }

       return accumulate(cardPoints.begin(), cardPoints.end(), 0) - mini;
    }
};
