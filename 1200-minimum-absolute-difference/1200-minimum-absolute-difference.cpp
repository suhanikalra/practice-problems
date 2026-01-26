class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        for (int i = 0; i < arr.size() - 1; i++) {
            pq.push({arr[i + 1] - arr[i], {arr[i], arr[i + 1]}});
        }
        vector<vector<int>> ans;
        auto diff = pq.top().first;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            if (cur.first == diff) {
                ans.push_back({cur.second.first, cur.second.second});
            } else {
                break;
            }
        }
        return ans;
    }
};