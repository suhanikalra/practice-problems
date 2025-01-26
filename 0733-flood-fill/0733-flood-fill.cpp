class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        
        if (originalColor == color) return image;
        
        int rows = image.size();
        int cols = image[0].size();
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;  
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while(!q.empty()) {
            auto ele = q.front();
            q.pop();
            int x = ele.first;
            int y = ele.second;
            
            for(int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if(newx >= 0 && newx < rows && 
                   newy >= 0 && newy < cols && 
                   image[newx][newy] == originalColor) {
                    image[newx][newy] = color;
                    q.push({newx, newy});
                }
            }
        }
        
        return image;
    }
};