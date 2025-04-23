class Solution {
void dfs(vector<vector<int>>& grid, int x, int y, int &count,vector<pair<int,int>>&ans)
{
    const int dx[] = {1,-1,0,0};
    const int dy[] = {0,0,-1,1};
    
    if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() ||  grid[x][y]==0){   return;}

    count++;
    grid[x][y]=0;
    ans.push_back({x,y});


    for( int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        dfs(grid,nx,ny,count,ans);
    }
}
public:

    int numDistinctIslands(vector<vector<int>>& grid) {
        vector<pair<int,int>>ans;
       set< vector<pair<int,int>>>st;

        for(int i=0;i<grid.size();i++)
        {
            for( int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int count=0;
                    ans.push_back({i,j});
                    dfs(grid,i,j,count,ans);
                    sort(ans.begin(),ans.end());
                    int xorigin= ans[0].first;int yorigin= ans[0].second;
                    for(int i=0;i<ans.size();i++){
                        ans[i].first-=xorigin;
                        ans[i].second-=yorigin;
                    }
                    st.insert(ans);
                    ans.clear();
                    
                }
            }
        }
        return st.size();
    }
};