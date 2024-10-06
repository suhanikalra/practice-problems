class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // The center node is the common node in the first two edges.
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        return edges[0][1];
    }
};
