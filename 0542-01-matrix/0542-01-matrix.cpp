class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row= mat.size();
        int col= mat[0].size();
        vector<vector<int>> ans(row,vector<int>(col,-1));
        queue <pair<int,int>> q;

        for(int i=0;i<row;i++){
            for (int j=0; j<col;j++){
                if(mat[i][j]==0){q.push({i,j});
                ans[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            auto p= q.front();
            q.pop();
            int X=p.first;
            int Y = p.second;
            int dx[]={0,1,-1,0};
            int dy[]={1,0,0,-1};
            for(int i= 0; i<4;i++){
            int newx= X+dx[i];
            int newy= Y+dy[i];

            if(newx<row && newy<col && newx>=0 && newy>=0 && ans[newx][newy]==-1 && mat[newx][newy]==1 ){
                ans[newx][newy]=ans[X][Y]+1;
                q.push({newx,newy});

            }






            }

        }
        return ans;
    }
};