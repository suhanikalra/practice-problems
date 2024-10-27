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

        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (const auto& entry : freq) {
            minHeap.push(entry.second);
        }

        while (k > 0 && !minHeap.empty()) {
            int frequency = minHeap.top();
            minHeap.pop();
            if (k >= frequency) {
                k -= frequency;
            } else {
                minHeap.push(frequency);
                break;
            }
        }

        return minHeap.size();
    }
};
