class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size();int m= mat[0].size();
        queue<tuple<int,int,int>>q;//x//y,dist
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        for(int i=0;i<mat.size();i++){
            for( int j=0;j<mat[0].size();j++){
               if( mat[i][j]==0) {q.push({i,j,0});
               dis[i][j]=0;}
            }
        }
int dx[]= {1,-1,0,0};
int dy[]= {0,0,-1,1};
        while( !q.empty()){
            auto size= q.size();
            auto [x, y, dist] = q.front();
            q.pop();
            for( int i=0;i<4;i++){
                int newx=x+dx[i];int newy=y+dy[i];
                if( newx>=0 and newx<n and newy>=0 and newy<m and dis[newx][newy]==INT_MAX and mat[newx][newy]==1){
                    dis[newx][newy]=dist+1;
                    q.push( { newx,newy,dist+1});
                }
            }
           
            

        }
        return dis;
    }
};