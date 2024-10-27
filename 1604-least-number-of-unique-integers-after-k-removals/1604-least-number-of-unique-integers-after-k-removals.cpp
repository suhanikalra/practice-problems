#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    int findLeastNumOfUniqueInts(std::vector<int>& arr, int k) {
        std::unordered_map<int, int> freq;
        for (auto a : arr) {
            freq[a]++;
        }

        auto cmp = [](const std::pair<int, int>& left, const std::pair<int, int>& right) {
            return left.first > right.first;
        };
        
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> minHeap(cmp);

        for (const auto& entry : freq) {
            minHeap.push({entry.second, entry.first});
        }

        while (k > 0 && !minHeap.empty()) {
            auto [frequency, number] = minHeap.top();
            minHeap.pop();
            if (k >= frequency) {
                k -= frequency;
            } else {
                minHeap.push({frequency, number});
                break;
            }
        }

        return minHeap.size();
    }
};
