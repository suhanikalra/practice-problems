class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>>v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    v.push_back({i,j});
                }
            }
    }
for(int i=0;i<v.size();i++){
    auto x= v[i][0];
    auto y= v[i][1];
    for(int i=0;i<matrix[0].size();i++){
        matrix[x][i]=0; 
    }
    for(int i=0;i<matrix.size();i++){
        matrix[i][y]=0;
       
    }
    

    }
    }
};