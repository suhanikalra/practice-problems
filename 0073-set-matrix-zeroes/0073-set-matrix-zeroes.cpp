class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>x;vector<int>y;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){x.push_back(i);y.push_back(j);}
            }
        }
        
        for( auto i: x){
            for(int j=0;j<matrix[0].size();j++){
                matrix[i][j]=0;
            
        }}

        for( auto i: y){
            for(int j=0;j<matrix.size();j++){
                matrix[j][i]=0;
            
        }
        }

        return;
        


    }
};