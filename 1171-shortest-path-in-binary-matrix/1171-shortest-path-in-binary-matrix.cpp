class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); 
        
        // If the start or end is blocked, return -1
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        vector<vector<int>> visited(n, vector<int>(n, 0));  
        queue<pair<pair<int, int>, int>> q; 
        
        // 8 possible directions for movement: diagonal, vertical, and horizontal
        int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
        int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
        
        // Push the starting cell into the queue with distance 1
        q.push({{0, 0}, 1});
        visited[0][0] = 1;  // Mark start as visited
        
        while (!q.empty()) {
            auto ele = q.front();
            int x = ele.first.first;
            int y = ele.first.second;
            int dist = ele.second;
            q.pop();
            
            // If we reach the bottom-right corner
            if (x == n-1 && y == n-1) {
                return dist;
            }
            
            // Explore all 8 possible directions
            for (int i = 0; i < 8; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                // Check if the new position is within bounds, is a 0, and not yet visited
                if (newx >= 0 && newy >= 0 && newx < n && newy < n && grid[newx][newy] == 0 && visited[newx][newy] == 0) {
                    q.push({{newx, newy}, dist + 1});
                    visited[newx][newy] = 1;  // Mark as visited
                }
            }
        }
        
        return -1;  // No path found
    }
};
