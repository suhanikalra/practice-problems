class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m= image.size();int n=image[0].size();int srccolor=image[sr][sc];
        if( srccolor==color)return image;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};

        while( !q.empty()){
            auto ele= q.front();
            q.pop();
            auto x=ele.first;
            auto y= ele.second;
            image[x][y]=color;
            for( int i=0; i<4; i++){
                int newx=x+dx[i];
                int newy= y+dy[i];
                if (newx >= 0 && newx < m &&
                    newy >= 0 && newy < n &&
                    image[newx][newy] == srccolor){
                        
                        q.push({newx,newy});
                    } 
            }
        }
        return image;
        
    }
};