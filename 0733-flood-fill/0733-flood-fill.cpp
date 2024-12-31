class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int dx[], int dy[], int inicolor) {
        image[sr][sc] = color;

        for (int i = 0; i < 4; i++) {
            if (sr + dx[i] >= 0 && sr + dx[i] < image.size() &&
                sc + dy[i] >= 0 && sc + dy[i] < image[0].size() &&
                image[sr + dx[i]][sc + dy[i]] == inicolor) {
                dfs(image, sr + dx[i], sc + dy[i], color, dx, dy, inicolor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        int inicolor = image[sr][sc];

        if (inicolor != color) {
            dfs(image, sr, sc, color, dx, dy, inicolor);
        }

        return image;
    }
};