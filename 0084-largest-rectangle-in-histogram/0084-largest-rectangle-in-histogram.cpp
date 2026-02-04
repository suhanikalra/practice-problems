class Solution {
public:
    // Next Smaller to Left
    vector<int> NSL(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        stack<pair<int, int>> st; 

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first >= heights[i]) {
                st.pop();
            }

            if (st.empty()) {
                left[i] = -1;
            } else {
                left[i] = st.top().second;
            }

            st.push({heights[i], i});
        }
        return left;
    }

    // Next Smaller to Right
    vector<int> NSR(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n);
        stack<pair<int, int>> st; 

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first >= heights[i]) {
                st.pop();
            }

            if (st.empty()) {
                right[i] = n; 
            } else {
                right[i] = st.top().second;
            }

            st.push({heights[i], i});
        }
        return right;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left = NSL(heights);
        vector<int> right = NSR(heights);
        int maxArea = *max_element(heights.begin(),heights.end());

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = width * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
