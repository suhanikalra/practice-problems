class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int,int>> stocks;
        for (int i = 0; i < n; i++) {
            stocks.push_back({capital[i], profits[i]});
        }

        sort(stocks.begin(), stocks.end());

        priority_queue<int> pq; // max-heap for profits
        int i = 0;

        while (k--) {
            while (i < n && stocks[i].first <= w) {
                pq.push(stocks[i].second);
                i++;
            }

            if (pq.empty()) break;

            w += pq.top();
            pq.pop();
        }

        return w;
    }
};
