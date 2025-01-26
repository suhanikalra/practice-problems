class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),-1));
       
        queue<pair<pair<int, int>, int>> q;
         for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){ans[i][j]=0;
                q.push({{i,j},0});}
            }
        }
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
        while(!q.empty()){
            
            auto ele= q.front();
            int x= ele.first.first;
            int y= ele.first.second;
            int distance= ele.second;
            q.pop();

            for(int i=0;i<4;i++){
                int newx= x+dx[i];
                int newy= y+dy[i];
                if(newx>=0 and newx<mat.size() and newy>=0 and newy<mat[0].size() and mat[newx][newy]==1 and ans[newx][newy]==-1){
                ans[newx][newy]= distance+1;
                
                q.push({{newx,newy},distance+1});}

            }

            
        }
        return ans;
       
    }
};